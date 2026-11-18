// SPDX-License-Identifier: BSD-3-Clause
// The sentence Sparky Stereo OS shows to whoever sets render.stereo_eye_angle in the edition's build, where the separation of a
// 3D window is the person's depth limits and nothing else: in the ten languages of the edition (en, pl, pt_BR, fr, de, es, ja, ko,
// zh_CN, zh_TW), the language being the first of LANGUAGE, LC_ALL, LC_MESSAGES and LANG that names one of them (English otherwise).
#ifndef f3d_depth_notice_h
#define f3d_depth_notice_h

#include <cstdlib>
#include <string>

namespace f3d::detail
{
inline const char* depthFollowsDesktopNotice()
{
  static const char* const table[] = {
    "3D depth follows the desktop's depth limits: render.stereo_eye_angle is not used",
    "Głębia 3D wynika z limitów głębi pulpitu: render.stereo_eye_angle nie jest używane",
    "A profundidade 3D segue os limites de profundidade do desktop: render.stereo_eye_angle não é usado",
    "La profondeur 3D suit les limites de profondeur du bureau : render.stereo_eye_angle n’est pas utilisé",
    "Die 3D-Tiefe folgt den Tiefengrenzen des Desktops: render.stereo_eye_angle wird nicht verwendet",
    "La profundidad 3D sigue los límites de profundidad del escritorio: render.stereo_eye_angle no se usa",
    "3D奥行きはデスクトップの奥行きの上限に従います: render.stereo_eye_angle は使われません",
    "3D 깊이는 데스크톱의 깊이 한계를 따릅니다: render.stereo_eye_angle은 사용되지 않습니다",
    "3D 深度跟随桌面的深度限制：不使用 render.stereo_eye_angle",
    "3D 深度跟隨桌面的深度限制：不使用 render.stereo_eye_angle",
  };
  static const char* const names[] = { "en", "pl", "pt_BR", "fr", "de", "es", "ja", "ko", "zh_CN", "zh_TW" };
  for (const char* variable : { "LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG" })
  {
    const char* value = std::getenv(variable);
    if (!value || !*value)
    {
      continue;
    }
    std::string language(value);
    language = language.substr(0, language.find(':'));
    language = language.substr(0, language.find('.'));
    for (int i = 0; i < 10; i++)
    {
      const std::string name = names[i];
      if (language == name || (name.size() == 2 && language.compare(0, 2, name) == 0) ||
        (name == "pt_BR" && language.compare(0, 2, "pt") == 0))
      {
        return table[i];
      }
    }
    if (language != "C")
    {
      break;
    }
  }
  return table[0];
}
}
#endif
