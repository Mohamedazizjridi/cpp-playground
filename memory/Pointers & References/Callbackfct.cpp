#include <iostream>
using namespace std;

// Event handler
void onButtonClick() {
    cout << "Button clicked!" << endl;
}

void onButtonHover() {
    cout << "Mouse over button!" << endl;
}

class Button {
private:
    void (*clickHandler)();
    void (*hoverHandler)();
    
public:
    void setClickHandler(void (*handler)()) {
        clickHandler = handler;
    }
    
    void setHoverHandler(void (*handler)()) {
        hoverHandler = handler;
    }
    
    void click() {
        if(clickHandler) clickHandler();
    }
    
    void hover() {
        if(hoverHandler) hoverHandler();
    }
};

int main() {
    Button btn;
    btn.setClickHandler(onButtonClick);
    btn.setHoverHandler(onButtonHover);
    
    btn.click();  // Output: Button clicked!
    btn.hover();  // Output: Mouse over button!
    
    return 0;
}
