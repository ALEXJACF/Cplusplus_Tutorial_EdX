    #include <windows.h>
    
    #define FILE_MENU_NEW 1
	#define FILE_MENU_OPEN 2
	#define FILE_MENU_EXIT 3
    const char g_szClassName[] = "myWindowClass";
    HMENU hMenu;
    
    void AddMenus(HWND hWnd);
    // Step 4: the Window Procedure
    LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch(msg)
        {	
        	case WM_COMMAND:
        		switch(wParam)
        {	
        	case FILE_MENU_NEW:
        		MessageBeep(MB_OK);
        		break;
        	case FILE_MENU_OPEN:
        		MessageBeep(MB_ICONINFORMATION);
        		break;
        	case FILE_MENU_EXIT:
        		DestroyWindow(hwnd);
        		break;
        	
            default:
                break;
        }
        		break;
        	case WM_CREATE:
        		AddMenus(hwnd);
        		break;
            case WM_CLOSE:
                DestroyWindow(hwnd);
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
            break;
            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        return 0;
    }
    
    void AddMenus(HWND hWnd){
    	hMenu = CreateMenu();
    	HMENU hsecondaryMenu = CreateMenu();
    	
    	AppendMenu(hsecondaryMenu,MF_STRING,FILE_MENU_NEW,"New");
    	AppendMenu(hsecondaryMenu,MF_STRING,FILE_MENU_OPEN,"Open");
    	AppendMenu(hsecondaryMenu,MF_SEPARATOR,NULL,NULL);
    	AppendMenu(hsecondaryMenu,MF_STRING,FILE_MENU_EXIT,"Exit");	
    	
    	AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hsecondaryMenu,"File");
    	AppendMenu(hMenu,MF_POPUP,2,"Halp");
    	
    	
    	SetMenu(hWnd,hMenu);
	}
    
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        LPSTR lpCmdLine, int nCmdShow)
    {
        WNDCLASSEX wc;
        HWND hwnd;
        MSG Msg;
        //Step 1: Registering the Window Class
        wc.cbSize        = sizeof(WNDCLASSEX);
        wc.style         = 0;
        wc.lpfnWndProc   = WndProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = hInstance;
        wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
        wc.lpszMenuName  = NULL;
        wc.lpszClassName = g_szClassName;
        wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
        if(!RegisterClassEx(&wc))
        {
            MessageBox(NULL, "Window Registration Failed!", "Error!",
                MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
        // Step 2: Creating the Window
        hwnd = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            g_szClassName,
            "cenas <(\")",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
            NULL, NULL, hInstance, NULL);
        if(hwnd == NULL)
        {
            MessageBox(NULL, "Window Creation Failed!", "Error!",
                MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);
        // Step 3: The Message Loop
        while(GetMessage(&Msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }
        return Msg.wParam;
    }
