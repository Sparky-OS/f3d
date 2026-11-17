#ifndef f3d_window_h
#define f3d_window_h

#include "camera.h"
#include "export.h"
#include "image.h"

/// @cond
#include <string>
/// @endcond

namespace f3d
{
/**
 * @class   window
 * @brief   Abstract class to render in a window or an image
 *
 * A class to render things in a window or an image.
 * An icon and windowName can be set which can be shown by a window manager.
 */
class F3D_EXPORT window
{
public:
  /**
   * Enumeration of supported window types
   * - NONE: A mock window without rendering capabilities.
   * - EXTERNAL: An external window that assume the OpenGL context would have been created by
   * another framework.
   * - GLX: A window using GLX.
   * - WGL: A window using WGL.
   * - COCOA: A window using COCOA.
   * - EGL: An offscreen window using hardware acceleration that can run headless.
   * - OSMESA: An offscreen window using software rendering that is always run headless.
   * - WASM: A webassembly window (when libf3d is built with emscripten).
   * - UNKNOWN: An unknown window (should not happen).
   */
  enum class Type : unsigned char
  {
    NONE,
    EXTERNAL,
    GLX,
    WGL,
    COCOA,
    EGL,
    OSMESA,
    WASM,
    UNKNOWN
  };

  /**
   * Get the type of the window.
   */
  [[nodiscard]] virtual Type getType() = 0;

  /**
   * Is the window offscreen.
   */
  [[nodiscard]] virtual bool isOffscreen() = 0;

  /**
   * Return true when the window draws the two eyes of a stereo pair (render.stereo is on and the
   * window could be made stereo capable). Call it after a render: the window is made stereo capable
   * when it is first rendered.
   */
  [[nodiscard]] virtual bool isStereo() = 0;

  /**
   * The state of the person's depth limits for a stereo window whose eye angle is not given
   * (render.stereo_eye_angle is zero): the desktop (Stereo KWin) hands them over per window and
   * the separation of the two eyes follows them.
   * UNUSED: no stereo window, or an angle was given. DELIVERED: the limits are in use.
   * NOT_OFFERED: the compositor offers no limits. NOT_DELIVERED: offered, not delivered yet.
   * NOT_READABLE: this window or build cannot read them. In the last three the two eyes are the same picture.
   */
  enum class stereo_depth_state
  {
    UNUSED,
    DELIVERED,
    NOT_OFFERED,
    NOT_DELIVERED,
    NOT_READABLE
  };

  /**
   * Poll the depth limits of the window (one property read). Sets changed when the state or the
   * limits are not what the previous call returned, so a program can render again and say why.
   */
  [[nodiscard]] virtual stereo_depth_state pollStereoDepth(bool& changed) = 0;

  /**
   * Get the camera provided by the window.
   */
  [[nodiscard]] virtual camera& getCamera() = 0;

  /**
   * Perform a render of the window to the screen.
   * All dynamic options are updated if needed.
   * Return true on success, false otherwise.
   */
  virtual bool render() = 0;

  /**
   * Perform a render of the window to the screen and save the result in a f3d::image.
   * of ChannelType BYTE and 3 or 4 components (RGB or RGBA).
   * Set noBackground to true to have a transparent background.
   * Returns the resulting f3d::image.
   */
  [[nodiscard]] virtual image renderToImage(bool noBackground = false) = 0;

  /**
   * Set the size of the window.
   */
  virtual window& setSize(int width, int height) = 0;

  /**
   * Get the width of the window.
   */
  [[nodiscard]] virtual int getWidth() const = 0;

  /**
   * Get the height of the window.
   */
  [[nodiscard]] virtual int getHeight() const = 0;

  /**
   * Set the position of the window.
   */
  virtual window& setPosition(int x, int y) = 0;

  /**
   * Set the icon to be shown by a window manager.
   * icon should be an unsigned char array.
   * iconSize should be the sizeof(icon).
   */
  virtual window& setIcon(const unsigned char* icon, size_t iconSize) = 0;

  /**
   * Set the window name to be shown by a window manager.
   */
  virtual window& setWindowName(std::string_view windowName) = 0;

  /**
   * Convert a point in display coordinate to world coordinate.
   */
  [[nodiscard]] virtual point3_t getWorldFromDisplay(const point3_t& displayPoint) const = 0;

  /**
   * Convert a point in world coordinate to display coordinate.
   */
  [[nodiscard]] virtual point3_t getDisplayFromWorld(const point3_t& worldPoint) const = 0;

protected:
  //! @cond
  window() = default;
  virtual ~window() = default;
  window(const window&) = delete;
  window(window&&) = delete;
  window& operator=(const window&) = delete;
  window& operator=(window&&) = delete;
  //! @endcond
};
}

#endif
