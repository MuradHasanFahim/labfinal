// Concrete Windows Scrollbar
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
    
    // Concrete Linux Scrollbar
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
    
    // Windows Factory
    class WindowsFactory : public GUIFactory {
    public:
        std::unique_ptr<Window> createWindow() const override {
            return std::make_unique<WindowsWindow>();
        }
    
        std::unique_ptr<Scrollbar> createScrollbar() const override {
            return std::make_unique<WindowsScrollbar>();
        }
    };
    
    // Linux Factory
    class LinuxFactory : public GUIFactory {
    public:
        std::unique_ptr<Window> createWindow() const override {
            return std::make_unique<LinuxWindow>();
        }
    
        std::unique_ptr<Scrollbar> createScrollbar() const override {
            return std::make_unique<LinuxScrollbar>();
        }
    };
    
    // Client Code
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