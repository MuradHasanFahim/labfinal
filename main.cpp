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

class LinuxScrollbar : public Scrollbar {
        public:
            void render() const override {
                std::cout << "Rendering Linux Scrollbar" << std::endl;
            }
        };
        
        // Abstract Factory Interface
class GUIFactory {
        public:
            virtual std::unique_ptr<Window> createWindow() const = 0;
            virtual std::unique_ptr<Scrollbar> createScrollbar() const = 0;
            virtual ~GUIFactory() = default;
        };
        class WindowsFactory : public GUIFactory {
            public:
                std::unique_ptr<Window> createWindow() const override {
                    return std::make_unique<WindowsWindow>();
                }
            
                std::unique_ptr<Scrollbar> createScrollbar() const override {
                    return std::make_unique<WindowsScrollbar>();
                }
            };
            class LinuxFactory : public GUIFactory {
                public:
                    std::unique_ptr<Window> createWindow() const override {
                        return std::make_unique<LinuxWindow>();
                    }
                
                    std::unique_ptr<Scrollbar> createScrollbar() const override {
                        return std::make_unique<LinuxScrollbar>();
                    }
                };
                void renderGUI(const GUIFactory& factory) {
                    auto window = factory.createWindow();
                    auto scrollbar = factory.createScrollbar();
                
                    window->render();
                    scrollbar->render();
                }                         
                int main() {
                    std::cout << "Using Windows GUI:" << std::endl;
                    WindowsFactory windowsFactory;
                    renderGUI(windowsFactory);
                
                    std::cout << "\nUsing Linux GUI:" << std::endl;
                    LinuxFactory linuxFactory;
                    renderGUI(linuxFactory);
                
                    return 0;
                }               