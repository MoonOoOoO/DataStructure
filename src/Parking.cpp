#include <fstream>
#include "../include/Parking.h"

Stack<car> tempParking(MAXIMUM);
Queue<car> waitingQueue;
car c;
int position = 1;

void enterParking(Stack<car> &parking) {
    cout << "请输入车牌号: ";
    cin >> c.number;
    cout << endl;
    if (parking.IsFull()) {
        cout << "车位已满，进入等待队列" << endl;
        waitingQueue.enQueue(c);
        return;
    } else {
        c.a_time = time(NULL);
        parking.push(c);
        cout << "车  牌: " << c.number << endl;
        cout << "车  位: " << position++ << "号" << endl;
        cout << "进场时间: " << getTime(c.a_time) << endl;
        cout << "出场时间: " << endl;
        cout << "停车费: " << endl;
    }
    cout << endl;
}

void quitParking(Stack<car> &parking, string quitCar) {
    ofstream out;
    out.open("record.txt", ios::app);
    if (!out) {
        cout << "打开文件出错" << endl;
        return;
    }
    if (parking.IsEmpty()) {
        cout << "停车场目前未停留车辆" << endl;
        cout << endl;
        return;
    }
    car temp;
    while (parking.getTop().number != quitCar) {
        temp = parking.pop();
        position--;
        tempParking.push(temp);
        if (parking.IsEmpty()) {
            cout << "无所输入车牌号车辆，请重新输入" << endl;
            cout << endl;
            while (!tempParking.IsEmpty()) {
                temp = tempParking.pop();
                parking.push(temp);
                position++;
            }
            return;
        }
    }
    time_t nowTime = time(NULL);
    out << parking.getTop().number << "_" << --position << "_" << getTime(parking.getTop().a_time) << "_"
        << getTime(nowTime) << "_" << difftime(nowTime, (parking.getTop().a_time)) << endl;
    cout << "车  牌: " << parking.getTop().number << endl;
    cout << "车  位: " << position << "号" << endl;
    cout << "进场时间: " << getTime(parking.getTop().a_time) << endl;
    cout << "出场时间: " << getTime(nowTime) << endl;
    cout << "停车费: " << difftime(nowTime, parking.pop().a_time) << "元" << endl;
    cout << endl;
    if (!waitingQueue.IsEmpty()) {
        temp = waitingQueue.deQueue();
        temp.a_time = time(NULL);
        cout << "车  牌: " << temp.number << endl;
        cout << "车  位: " << position++ << "号" << endl;
        cout << "进场时间: " << getTime(temp.a_time) << endl;
        cout << "出场时间: " << endl;
        cout << "停车费: " << endl;
        parking.push(temp);
        cout << endl;
    }
    while (!tempParking.IsEmpty()) {
        temp = tempParking.pop();
        parking.push(temp);
        position++;
    }
}

void showParking(Stack<car> &parking) {
    car c;
    time_t nowTime = time(NULL);
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t     当前停车场停留车辆" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "    车  牌\t|" << "    车  位\t|" << "\t进场时间\t|" << "\t出场时间\t|" << "    停车费" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    while (!parking.IsEmpty()) {
        c = parking.pop();
        position--;
        cout << "     " << c.number << "\t|";
        cout << "      " << position << "号\t|";
        cout << "  " << getTime(c.a_time) << "  |";
        cout << "\t出场时间\t|";
        cout << "      " << difftime(nowTime, c.a_time) << "元";
        cout << endl;
        tempParking.push(c);
    }
    while (!tempParking.IsEmpty()) {
        c = tempParking.pop();
        parking.push(c);
        position++;
    }
    if (parking.IsEmpty()) {
        cout << endl;
        cout << "\t\t\t\t     停车场暂无停留车辆" << endl;
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void showRecord() {
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t     停车场停车收费记录" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "    车  牌\t|" << "    车  位\t|" << "\t进场时间\t|" << "\t出场时间\t|" << "    停车费" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    ifstream in;
    string record;
    in.open("record.txt");
    if (!in) {
        cout << "打开文件出错" << endl;
        return;
    }
    getline(in, record);
    if (record.length() == 0) {
        cout << endl;
        cout << "\t\t\t\t     暂无停车场收费记录" << endl;
        cout << "----------------------------------------------------------------------------------------------"
             << endl;
        cout << endl;
        return;
    }
    in.seekg(0, ios::beg);
    while (!in.eof()) {
        getline(in, record);
        vector<string> result = split(record, "_");
        if (result[0] == "")
            break;
        cout << "     " << result[0] << "\t|";
        cout << "      " << result[1] << "号\t|";
        cout << "  " << result[2] << "  |";
        cout << "  " << result[3] << "  |";
        cout << "      " << result[4] << "元";
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------"
             << endl;
    }
    cout << endl;
    in.close();
}

vector<string> split(string str, string pattern) {
    string::size_type pos;
    vector<string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (unsigned int i = 0; i < size; i++) {
        pos = str.find(pattern, i);
        if (pos < size) {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

string getTime(time_t t) {
    char timeStamp[64];
    strftime(timeStamp, sizeof(timeStamp), "%Y/%m/%d %X", localtime(&t));
    return timeStamp;
}