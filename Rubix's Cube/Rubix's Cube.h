#pragma once

#if defined (DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "RubixCubeUtil.h"
#include "RubixCubeTimer.h"

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")


using Microsoft::WRL::ComPtr;

class RubixCubeApp {

protected:
	RubixCubeApp(HINSTANCE hInstance);
	RubixCubeApp(const RubixCubeApp& rhs) = delete;
	RubixCubeApp& operator=(const RubixCubeApp& rhs) = delete;
	virtual ~RubixCubeApp();


public:
	static RubixCubeApp* getApp();

	HINSTANCE AppInstance() const;
	HWND mainWnd() const;

	float aspectRatio() const;
	int runApp();
	
	virtual void updateFaceAnimation();
	virtual void Initialize();

	LRESULT CALLBACK msgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

protected:
	virtual void  createRtvAndDsvDescriptorHeaps();
	virtual void onResized();
	virtual void update();

	virtual void onMouseDown(WPARAM btnState, int x, int y) { }
	virtual void onMouseUp(WPARAM btnState, int x, int y) { }
	virtual void onMouseMove(WPARAM btnState, int x, int y) { }

protected:
	bool initMainWindow();
	bool initDirect3D();

	void createCommandObjects();
	void createSwapChain();

	void flushCommandQueue();

	ID3D12Resource* CurrentBackBuffer()const;
	D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView()const;
	D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView()const; 

	void calculateFramestate();

	void logAdaptives();
	void LogAdativeOutput(IDXGIAdapter* adapter);
	void logOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);

protected:
	static RubixCubeApp* mApp;
	
	HINSTANCE mhAppInst = nullptr; 
	HWND mhmainWnd = nullptr;
	bool mAppPaused = false;
	bool mMinimized = false;
	bool mMaximized = false;
	bool mResized = false;
	bool mFullScreenState = false;
	
	bool m4xMsaaState = false;
	UINT m4xMassQuality = 0;

	RubixCubeTimer* mTimer;

	ComPtr<IDXGIFactory4> mdxgiFactory;
	ComPtr<IDXGISwapChain> mSwapChain;
	ComPtr<ID3D12Device> md3dDevice;

};		