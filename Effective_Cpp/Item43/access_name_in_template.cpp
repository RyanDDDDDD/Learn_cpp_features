#include <iostream>

class MsgInfo {};

class Company1 {
    public:
    void sendClearText () {
    }

    void sendSecretText () {
    }
};

class Company2 {
    public:
    void sendClearText () {
    }

    void sendSecretText () {
    }
};

template <typename Company> class MsgSender {
    public:
    void sendClear (const MsgInfo& m) {
    }

    void sendSecret (const MsgInfo& m) {
    }
};

template <typename Company> class LoggingMsgSender : public MsgSender<Company> {
    public:
    void sendClearMsg (const MsgInfo& m) {
        // do stuff 1

        // the code below wont work, because when compiler try to compile the
        // code, it cannot assume that the sendClear is the method from base
        // class, as it doesnt know what the base class is, all it can do is to
        // simpliy pops up error that thsi method doesnt exist in current class

        // sendClear (m);

        // ways to declare the method from base class
        // 1. explicity tell compiler this method is from base class
        MsgSender<Company>::sendClear (m);

        // 2. this method is in current class (includes base class)
        this->sendClear (m);

        // 3. using a method from base class
        using MsgSender<Company>::sendClear;
        sendClear (m);

        // do stuff 2
    }

    void sendSecretMsg (const MsgInfo& m) {
        // do stuff 1
        MsgSender<Company>::sendSecret (m);
        // do stuff 2
    }
};

int main () {
}