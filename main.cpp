#include <iostream>
#include <memory>

// Interface for Window
class Window {
public:
    virtual void render() const = 0;
    virtual ~Window() = default;
};

// Interface for Scrollbar
class Scrollbar {
public:
    virtual void render() const = 0;
    virtual ~Scrollbar() = default;
};

// Concrete Windows Window
class WindowsWindow : public Window {
public:
    void render() const override {
        std::cout << "Rendering Windows Window" << std::endl;
    }
};

class WindowsScrollbar : public Scrollbar {
    public:
        void render() const override {
            std::cout << "Rendering Windows Scrollbar" << std::endl;
        }
    };
    
    // Concrete Linux Window
    class LinuxWindow : public Window {
    public:
        void render() const override {
            std::cout << "Rendering Linux Window" << std::endl;
        }
    };

    
