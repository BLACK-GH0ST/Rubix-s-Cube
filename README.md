# Rubixs Cude

Prerequisites
Windows 10/11 with a GPU + driver that supports DirectX 12 Ultimate / Mesh Shaders (Shader Model 6.5+).
Visual Studio 2019/2022 with the Desktop C++ workload.
Windows SDK (latest recommended) and the DirectX Shader Compiler (DXC) available; Visual Studio can use DXC when HLSL Shader Model >= 6.

Build options
Option A: Compile HLSL at build time using dxc.exe in a custom build step and produce .cso blobs.
Option B: Compile at runtime using the IDxcCompiler3 API (helper in DxcHelper.*).

How to run
Open the provided solution or create a new Win32 project and drop the src/ files in.
Make sure include/lib paths include d3d12.lib, dxguid.lib, dxcompiler.lib (if you link to DXC). Alternatively use runtime LoadLibrary for dxcompiler.dll.
Build and run. The app will check for shader model support and print whether mesh shaders are available.