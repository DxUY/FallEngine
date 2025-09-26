#pragma once

#include "FallEngine/Window.h"
#include <SDL3/SDL.h>
#include <string>

#include "FallEngine/Events/ApplicationEvent.h"
#include "FallEngine/Events/KeyEvent.h"
#include "FallEngine/Events/MouseEvent.h"

namespace FallEngine {

	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		void SetEventCallBack(const EventCallBackFn& callback) override { m_Data.EventCallBack = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_Data.VSync; }

		// === New mouse query functions ===
		std::pair<float, float> GetMousePos() const;
		std::pair<float, float> GetMouseDelta() const;

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		SDL_Window* m_Window = nullptr;
		SDL_GLContext m_Context = nullptr;

		struct WindowData {
			std::string Title = "Untitled";
			unsigned int Width = 800;
			unsigned int Height = 600;
			bool VSync = true;

			EventCallBackFn EventCallBack = nullptr;

			// Mouse state tracking
			float MouseX = 0.0f, MouseY = 0.0f;
			float LastMouseX = 0.0f, LastMouseY = 0.0f;
			float DeltaX = 0.0f, DeltaY = 0.0f;
		};

		WindowData m_Data;
	};

}