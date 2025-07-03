#pragma once

#ifdef F_PLATFORM_WINDOWS

extern FallEngine::Application* FallEngine::CreateApplication();

int main(int argc, char** argv)
{
    FallEngine::Log::Init();

    auto app = FallEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif