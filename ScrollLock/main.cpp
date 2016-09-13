#include <windows.h>

static void EnableLock(UINT uCode)
{
    if (GetKeyState(uCode) & 1)
        return;
    auto vk = MapVirtualKeyA(uCode, MAPVK_VK_TO_VSC);
    keybd_event(uCode, vk, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(uCode, vk, KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY, 0);
}

int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
    )
{
    EnableLock(VK_SCROLL);
    return 0;
}