#pragma once

#include <GLFW/glfw3.h>
#include "core/window.h"
#include "events/application_event.h"
#include "events/key_event.h"
#include "events/mouse_event.h"

namespace hazel {

    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();

        void on_update() override;

        inline unsigned int get_width() const override { return m_data.width; }
        inline unsigned int get_height() const override { return m_data.height; }

        // Window attributes
        inline void set_event_callback(const EventCallbackFn& callback) override {
            m_data.event_callback = callback;
        };
        void set_vsync(bool enabled) override;
        bool is_vsync() const override;

    private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

        GLFWwindow* m_window;

        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool vsync;
            EventCallbackFn event_callback;
        };

        WindowData m_data;
    };

}