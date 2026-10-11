
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    stack<string> undoStack;
    stack<string> redoStack;
    string document;

public:
    void type(string word) {
        if (document.empty())
            document = word;
        else
            document += " " + word;

        undoStack.push(word);

        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() {
        if (undoStack.empty())
            return;

        string word = undoStack.top();
        undoStack.pop();
        redoStack.push(word);

        if (document.length() == word.length())
            document = "";
        else
            document.erase(document.length() - word.length() - 1);
    }

    void redo() {
        if (redoStack.empty())
            return;

        string word = redoStack.top();
        redoStack.pop();

        if (document.empty())
            document = word;
        else
            document += " " + word;

        undoStack.push(word);
    }

    void print() {
        if (document.empty())
            cout << "Document: Empty" << endl;
        else
            cout << "Document: " << document << endl;
    }
};

int main() {
    TextEditor e;

    e.type("Hello");
    e.print();

    e.type("World");
    e.print();

    e.undo();
    e.print();

    e.redo();
    e.print();

    e.undo();
    e.print();

    e.type("There");
    e.print();

    e.redo();
    e.print();

    return 0;
}
