#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class State {
private:
    int step;           //��ִ�в�����
    int leftState;      //��ߵ�̺��״̬��0�ɾ���1����
    int rightState;     //�ұߵ�̺��״̬��0�ɾ���1����
    int suckerLocation; //��������λ�ã�0��1��
public:
    bool init(int l, int r, int s) {
        if ((l == 0 || l == 1) && (r == 0 || r == 1) && (s == 0 || s == 1)) {
            this->leftState = l;
            this->rightState = r;
            this->suckerLocation = s;
            this->step = 0;
            return true;
        } else {
            cout << "״̬��������������" << endl;
            return false;
        }
    }

    void toLeft() {
        if (this->suckerLocation == 1) {
            this->suckerLocation = 0;
            ++this->step;
            cout << "����" << endl;
            this->printState();
        } else {
            cout << "�����·����" << endl;
        }
    }

    void toRight() {
        if (this->suckerLocation == 0) {
            this->suckerLocation = 1;
            ++this->step;
            cout << "����" << endl;
            this->printState();
        } else {
            cout << "�ұ���·����" << endl;
        }
    }

    void suck() {
        if (this->suckerLocation == 0) {
            this->leftState = 0;
            ++this->step;
            cout << "����" << endl;
            this->printState();
        }
        if (this->suckerLocation == 1) {
            this->rightState = 0;
            ++this->step;
            cout << "����" << endl;
            this->printState();
        }
    }

    void printState() {
        cout << "(" << this->step << "," << this->leftState << "," << this->rightState << ","
             << this->suckerLocation << ")" << endl;
    }
};

bool init(State *s) {
    int l;
    int r;
    int sl;
    cout << "��������ߵ�̺��״̬��";
    cin >> l;
    cout << "�������ұߵ�̺��״̬��";
    cin >> r;
    cout << "��������������λ�ã�";
    cin >> sl;
    return s->init(l, r, sl);
}

bool order(State *s) {
    cout << "��������Ҫִ�еĲ���(l,r,s)��";
    char order;
    cin >> order;
    if (order == 'l') {
        s->toLeft();
    } else if (order == 'r') {
        s->toRight();
    } else if (order == 's') {
        s->suck();
    } else {
        cout << "�����������������" << endl;
        return true;
    }
    while (true) {
        cout << "���Ƿ�Ҫ����������(y/n)";
        cin >> order;
        if (order == 'y') {
            return true;
        } else if (order == 'n') {
            return false;
        } else {
            cout << "�����������������" << endl;
        }
    }

}

int main() {
    State s{};
    bool flag = false;
    while (!flag) {
        flag = init(&s);
    }
    s.printState();
    while (flag) {
        flag = order(&s);
    }
    return 0;
}