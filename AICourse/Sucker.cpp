#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class State {
private:
    int step;           //ÒÑÖ´ÐÐ²½ÖèÊý
    int leftState;      //×ó±ßµØÌºµÄ×´Ì¬£¬0¸É¾»£¬1°¹Ôà
    int rightState;     //ÓÒ±ßµØÌºµÄ×´Ì¬£¬0¸É¾»£¬1°¹Ôà
    int suckerLocation; //Îü³¾Æ÷µÄÎ»ÖÃ£¬0×ó£¬1ÓÒ
public:
    bool init(int l, int r, int s) {
        if ((l == 0 || l == 1) && (r == 0 || r == 1) && (s == 0 || s == 1)) {
            this->leftState = l;
            this->rightState = r;
            this->suckerLocation = s;
            this->step = 0;
            return true;
        } else {
            cout << "×´Ì¬´íÎó£¬ÇëÖØÐÂÊäÈë" << endl;
            return false;
        }
    }

    void toLeft() {
        if (this->suckerLocation == 1) {
            this->suckerLocation = 0;
            ++this->step;
            cout << "×óÒÆ" << endl;
            this->printState();
        } else {
            cout << "×ó±ßÎÞÂ·¿É×ß" << endl;
        }
    }

    void toRight() {
        if (this->suckerLocation == 0) {
            this->suckerLocation = 1;
            ++this->step;
            cout << "ÓÒÒÆ" << endl;
            this->printState();
        } else {
            cout << "ÓÒ±ßÎÞÂ·¿É×ß" << endl;
        }
    }

    void suck() {
        if (this->suckerLocation == 0) {
            this->leftState = 0;
            ++this->step;
            cout << "Îü³¾" << endl;
            this->printState();
        }
        if (this->suckerLocation == 1) {
            this->rightState = 0;
            ++this->step;
            cout << "Îü³¾" << endl;
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
    cout << "ÇëÊäÈë×ó±ßµØÌºµÄ×´Ì¬£º";
    cin >> l;
    cout << "ÇëÊäÈëÓÒ±ßµØÌºµÄ×´Ì¬£º";
    cin >> r;
    cout << "ÇëÊäÈëÎü³¾Æ÷µÄÎ»ÖÃ£º";
    cin >> sl;
    return s->init(l, r, sl);
}

bool order(State *s) {
    cout << "ÇëÊäÈëÄúÒªÖ´ÐÐµÄ²Ù×÷(l,r,s)£º";
    char order;
    cin >> order;
    if (order == 'l') {
        s->toLeft();
    } else if (order == 'r') {
        s->toRight();
    } else if (order == 's') {
        s->suck();
    } else {
        cout << "ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë" << endl;
        return true;
    }
    while (true) {
        cout << "ÄúÊÇ·ñÒª¼ÌÐø²Ù×÷£¿(y/n)";
        cin >> order;
        if (order == 'y') {
            return true;
        } else if (order == 'n') {
            return false;
        } else {
            cout << "ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë" << endl;
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