#include <fstream>
#include "../include/Parking.h"

Stack<car> tempParking(MAXIMUM);
Queue<car> waitingQueue;
car c;
int position = 1;

void enterParking(Stack<car> &parking) {
    cout << "�����복�ƺ�: ";
    cin >> c.number;
    cout << endl;
    if (parking.IsFull()) {
        cout << "��λ����������ȴ�����" << endl;
        waitingQueue.enQueue(c);
        return;
    } else {
        c.a_time = time(NULL);
        parking.push(c);
        cout << "��  ��: " << c.number << endl;
        cout << "��  λ: " << position++ << "��" << endl;
        cout << "����ʱ��: " << getTime(c.a_time) << endl;
        cout << "����ʱ��: " << endl;
        cout << "ͣ����: " << endl;
    }
    cout << endl;
}

void quitParking(Stack<car> &parking, string quitCar) {
    ofstream out;
    out.open("record.txt", ios::app);
    if (!out) {
        cout << "���ļ�����" << endl;
        return;
    }
    if (parking.IsEmpty()) {
        cout << "ͣ����Ŀǰδͣ������" << endl;
        cout << endl;
        return;
    }
    car temp;
    while (parking.getTop().number != quitCar) {
        temp = parking.pop();
        position--;
        tempParking.push(temp);
        if (parking.IsEmpty()) {
            cout << "�������복�ƺų���������������" << endl;
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
    cout << "��  ��: " << parking.getTop().number << endl;
    cout << "��  λ: " << position << "��" << endl;
    cout << "����ʱ��: " << getTime(parking.getTop().a_time) << endl;
    cout << "����ʱ��: " << getTime(nowTime) << endl;
    cout << "ͣ����: " << difftime(nowTime, parking.pop().a_time) << "Ԫ" << endl;
    cout << endl;
    if (!waitingQueue.IsEmpty()) {
        temp = waitingQueue.deQueue();
        temp.a_time = time(NULL);
        cout << "��  ��: " << temp.number << endl;
        cout << "��  λ: " << position++ << "��" << endl;
        cout << "����ʱ��: " << getTime(temp.a_time) << endl;
        cout << "����ʱ��: " << endl;
        cout << "ͣ����: " << endl;
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
    cout << "\t\t\t\t     ��ǰͣ����ͣ������" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "    ��  ��\t|" << "    ��  λ\t|" << "\t����ʱ��\t|" << "\t����ʱ��\t|" << "    ͣ����" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    while (!parking.IsEmpty()) {
        c = parking.pop();
        position--;
        cout << "     " << c.number << "\t|";
        cout << "      " << position << "��\t|";
        cout << "  " << getTime(c.a_time) << "  |";
        cout << "\t����ʱ��\t|";
        cout << "      " << difftime(nowTime, c.a_time) << "Ԫ";
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
        cout << "\t\t\t\t     ͣ��������ͣ������" << endl;
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void showRecord() {
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t     ͣ����ͣ���շѼ�¼" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "    ��  ��\t|" << "    ��  λ\t|" << "\t����ʱ��\t|" << "\t����ʱ��\t|" << "    ͣ����" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    ifstream in;
    string record;
    in.open("record.txt");
    if (!in) {
        cout << "���ļ�����" << endl;
        return;
    }
    getline(in, record);
    if (record.length() == 0) {
        cout << endl;
        cout << "\t\t\t\t     ����ͣ�����շѼ�¼" << endl;
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
        cout << "      " << result[1] << "��\t|";
        cout << "  " << result[2] << "  |";
        cout << "  " << result[3] << "  |";
        cout << "      " << result[4] << "Ԫ";
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
    str += pattern;//��չ�ַ����Է������
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