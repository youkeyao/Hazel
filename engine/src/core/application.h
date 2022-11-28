#pragma once

#include "core/window.h"
#include "core/layerstack.h"
#include "events/application_event.h"

namespace hazel {

    class Application
    {
    public:
        Application();
        virtual ~Application();
        void run();
        void on_event(Event& e);
        void push_layer(Layer* layer);
        void push_overlay(Layer* layer);
        inline Window& get_window() { return*m_window; }
        inline static Application& get() { return *m_instance; }
    private:
        bool on_window_close(WindowCloseEvent& e);
        bool on_window_resize(WindowResizeEvent& e);
        std::unique_ptr<Window> m_window;
        bool m_running = true;
        LayerStack m_layerstack;
        static Application* m_instance;
    };

    extern Application* create_application();

}