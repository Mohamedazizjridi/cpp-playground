#include <iostream>
#include <vector>
#include <string>

class Logger {
public:
    // Retrieve the single instance
    /*
        GetInstance() is a static method, so you call it without creating an object.
        It has a static local pointer variable s_instance that:
        is initialized only once, the first time GetInstance() is called.
        stores a pointer to a new Logger object.
        The method returns a reference to that same instance every time.
    */
    static Logger& GetInstance() {
        static Logger* s_instance = new Logger();
        return *s_instance;
    }
    void addMessage(std::string s) {
    m_messages.push_back(s);
    }

    void printMessages() {
    std::cout << "Accessing the log\n";
    for (auto& e : m_messages)
        std::cout << e << std::endl;
    }
private:
    Logger() { std::cout << "Logger was created\n"; }
    ~Logger() { std::cout << "Logger was Destructor\n"; }

    std::vector<std::string> m_messages;
}

int main() {
    Logger::GetInstance().addMessage("hello, message 1");
    Logger::GetInstance().addMessage("hello, message 2");
    Logger::GetInstance().addMessage("hello, message 3");
    Logger::GetInstance().printMessages();
}

