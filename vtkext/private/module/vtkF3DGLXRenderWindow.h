/**
 * @class   vtkF3DGLXRenderWindow
 * @brief   GLX context render window with UI support
 */

#ifndef vtkF3DGLXRenderWindow_h
#define vtkF3DGLXRenderWindow_h

#include <vtkXOpenGLRenderWindow.h>

class vtkF3DGLXRenderWindow : public vtkXOpenGLRenderWindow
{
public:
  static vtkF3DGLXRenderWindow* New();
  vtkTypeMacro(vtkF3DGLXRenderWindow, vtkXOpenGLRenderWindow);

  /**
   * Render at the size of one eye when the window holds a stereo pair.
   */
  void Start() override;

  /**
   * Read the person's depth limits that Stereo KWin gives this window, through libstereo-declare
   * (X11 property _KDE_NET_WM_STEREO_DEPTH_LIMITS). Returns the state of the limits:
   * 0 delivered (Sunk and Popped, in pixels of a view 1920 wide), 1 not offered by the compositor,
   * 2 offered and not delivered yet, 3 this build cannot read them. Cheap: one property read.
   */
  int UpdateStereoDepthLimits();

  vtkGetMacro(StereoDepthSunk, double);
  vtkGetMacro(StereoDepthPopped, double);
  vtkGetMacro(StereoDepthState, int);

protected:
  vtkF3DGLXRenderWindow();
  ~vtkF3DGLXRenderWindow() override;

  double StereoDepthSunk = 0.0;
  double StereoDepthPopped = 0.0;
  int StereoDepthState = 3;

private:
  vtkF3DGLXRenderWindow(const vtkF3DGLXRenderWindow&) = delete;
  void operator=(const vtkF3DGLXRenderWindow&) = delete;
};
#endif // vtkF3DGLXRenderWindow_h
