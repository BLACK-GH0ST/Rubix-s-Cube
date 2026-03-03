 // Rubix's Cube.cpp : Defines the entry point for the application.

#include <DirectXColors.h>

#include "RubixCubeUtil.h"     
#include "Rubix's Cube.h"  
#include "Rubix's Cube.rc"

using namespace DirectX;

struct Vertex {
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
	XMFLOAT2 uv;
};

struct InstanceData {
	XMFLOAT4X4 World;
	XMFLOAT4X4 color[6];
};

struct faceAnimation {
	bool active = false;
	float duration = 0.4f;
	float elapsed = 0.0f;
	float startAngle = 0.4f;
	float targetAngle = 90.4f;
};

// -------------------------------
// Register window class
// -------------------------------
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;                 // struct describing our window style

    wcex.cbSize = sizeof(WNDCLASSEX); // size of struct
    wcex.style = CS_HREDRAW | CS_VREDRAW;    // redraw if resized horizontally/vertically
    wcex.cbClsExtra = 0;                          // extra memory (not used here)
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;                  // app instance
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RUBIXSCUBE)); 
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); 
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);                       
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);      
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_RUBIXSCUBE);

    return RegisterClassExW(&wcex); // register class with Windows
}


RubixCubeApp::RubixCubeApp(HINSTANCE hInstance)
{

}

void RubixCubeApp::updateFaceAnimation () {
	
}

int WINAPI mainWin(HINSTANCE hInstance, HINSTANCE, PSTR, int mCmdshow) {

}