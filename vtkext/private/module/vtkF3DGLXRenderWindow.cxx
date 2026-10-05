#include <vtkObjectFactory.h>
#include <vtkVersion.h>

#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 3, 20240914)
#include <vtk_glad.h>
#include <vtkglad/include/glad/glx.h>
#else
#include <vtk_glew.h>
#endif

#include "vtkF3DGLXRenderWindow.h"

#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 5, 20251009)
#include "vtkX11Functions.h"
#else
#include <X11/Xlib.h>
#endif

//------------------------------------------------------------------------------
vtkF3DGLXRenderWindow::vtkF3DGLXRenderWindow() = default;

//------------------------------------------------------------------------------
vtkF3DGLXRenderWindow::~vtkF3DGLXRenderWindow() = default;

//------------------------------------------------------------------------------
void vtkF3DGLXRenderWindow::Start()
{
  // The X window of a declared stereo window holds both eyes side by side, so it is twice as wide
  // as one eye, and only the GLX drawable reports the size of one eye
  if (this->StereoRender && this->WindowId)
  {
    unsigned int width = 0;
    glXQueryDrawable(this->DisplayId, this->WindowId, GLX_WIDTH, &width);
    if (width > 0 && static_cast<int>(width) != this->Size[0])
    {
      this->vtkRenderWindow::SetSize(static_cast<int>(width), this->Size[1]);
    }
  }

  this->Superclass::Start();
}

//------------------------------------------------------------------------------
vtkF3DGLXRenderWindow* vtkF3DGLXRenderWindow::New()
{
#if VTK_VERSION_NUMBER >= VTK_VERSION_CHECK(9, 5, 20251009)
  // Check if the X display is available
  vtkX11FunctionsInitialize();

  if (vtkXOpenDisplay == nullptr || vtkXCloseDisplay == nullptr)
  {
    // libX11 cannot be open
    return nullptr;
  }

  Display* dpy = vtkXOpenDisplay(nullptr);
  if (dpy == nullptr)
  {
    // no display available
    return nullptr;
  }
  vtkXCloseDisplay(dpy);

  vtkX11FunctionsFinalize();
#else
  Display* dpy = XOpenDisplay(nullptr);
  if (dpy == nullptr)
  {
    return nullptr;
  }
  XCloseDisplay(dpy);
#endif

  VTK_STANDARD_NEW_BODY(vtkF3DGLXRenderWindow);
}
