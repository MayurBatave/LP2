#include <iostream>
#include <string>
using namespace std;

int main() {

    string message;

    cout << "===== Customer Support Chatbot =====" << endl;
    cout << "Type your message (type 'bye' to exit)\n" << endl;

    while (true) {

        cout << "You: ";
        getline(cin, message);

        // Exit
        if (message == "bye") {

            cout << "Bot: Thank you for chatting!" << endl;
            break;
        }

        // Greeting
        else if (message == "Hello" || message == "Hi") {

            cout << "Bot: Hello! How can I help you?" << endl;
        }

        // Product question
        else if (message == "What products do you provide?") {

            cout << "Bot: We provide laptops, mobiles, and accessories." << endl;
        }

        // Price question
        else if (message == "What is the price?") {

            cout << "Bot: Prices start from Rs. 10,000." << endl;
        }

        // Delivery question
        else if (message == "When will my order arrive?") {

            cout << "Bot: Delivery takes 3 to 5 business days." << endl;
        }

        // Contact question
        else if (message == "How can I contact support?") {

            cout << "Bot: Contact us at support@gmail.com." << endl;
        }

        // Default
        else {

            cout << "Bot: Sorry, I do not understand your question." << endl;
        }
    }

    return 0;
}