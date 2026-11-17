// SPDX-License-Identifier: BSD-3-Clause
// The sentences Sparky Stereo OS adds to F3D, in the ten languages of the edition (en, pl, pt_BR, fr, de, es, ja, ko,
// zh_CN, zh_TW). The language is the first of LANGUAGE, LC_ALL, LC_MESSAGES and LANG that names one of them; English
// is used when none does.
#ifndef F3DSparkyStrings_h
#define F3DSparkyStrings_h

#include <cstdlib>
#include <string>

namespace F3DSparkyStrings
{
enum Id
{
  Enable3D = 0,
  DisplaySettings,
  DisplaySettingsFailed,
  NoStereoWindow,
  Count
};

inline const char* Text(Id id)
{
  static const char* const table[][Count] = {
    // en
    { "Enable 3D", "Display Settings", "Display Settings could not be opened: kcmshell6 was not found",
      "3D could not be enabled: this display offers no stereo window" },
    // pl
    { "Włącz 3D", "Ustawienia ekranu", "Nie można otworzyć ustawień ekranu: nie znaleziono kcmshell6",
      "Nie można włączyć 3D: ten ekran nie udostępnia okna stereo" },
    // pt_BR
    { "Ativar 3D", "Configurações de tela", "Não foi possível abrir as configurações de tela: kcmshell6 não foi encontrado",
      "Não foi possível ativar o 3D: esta tela não oferece uma janela estéreo" },
    // fr
    { "Activer la 3D", "Paramètres d’affichage", "Impossible d’ouvrir les paramètres d’affichage : kcmshell6 est introuvable",
      "Impossible d’activer la 3D : cet affichage ne propose pas de fenêtre stéréo" },
    // de
    { "3D aktivieren", "Anzeigeeinstellungen", "Die Anzeigeeinstellungen konnten nicht geöffnet werden: kcmshell6 wurde nicht gefunden",
      "3D konnte nicht aktiviert werden: dieser Bildschirm bietet kein Stereo-Fenster" },
    // es
    { "Activar 3D", "Configuración de pantalla", "No se pudo abrir la configuración de pantalla: no se encontró kcmshell6",
      "No se pudo activar el 3D: esta pantalla no ofrece una ventana estéreo" },
    // ja
    { "3Dを有効にする", "ディスプレイ設定", "ディスプレイ設定を開けませんでした: kcmshell6 が見つかりません",
      "3Dを有効にできませんでした: このディスプレイはステレオウィンドウを提供していません" },
    // ko
    { "3D 켜기", "디스플레이 설정", "디스플레이 설정을 열 수 없습니다: kcmshell6을 찾을 수 없습니다",
      "3D를 켤 수 없습니다: 이 디스플레이는 스테레오 창을 제공하지 않습니다" },
    // zh_CN
    { "启用 3D", "显示设置", "无法打开显示设置：找不到 kcmshell6", "无法启用 3D：此显示器不提供立体窗口" },
    // zh_TW
    { "啟用 3D", "顯示設定", "無法開啟顯示設定：找不到 kcmshell6", "無法啟用 3D：此顯示器不提供立體視窗" },
  };
  static const char* const names[] = { "en", "pl", "pt_BR", "fr", "de", "es", "ja", "ko", "zh_CN", "zh_TW" };
  static int chosen = -1;
  if (chosen < 0)
  {
    chosen = 0;
    for (const char* variable : { "LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG" })
    {
      const char* value = std::getenv(variable);
      if (!value || !*value)
      {
        continue;
      }
      // the first entry of a LANGUAGE list, without its encoding
      std::string language(value);
      language = language.substr(0, language.find(':'));
      language = language.substr(0, language.find('.'));
      bool found = false;
      for (int i = 0; i < 10 && !found; i++)
      {
        const std::string name = names[i];
        if (language == name || (language.size() >= 2 && language.compare(0, 2, name, 0, 2) == 0 && name.size() == 2) ||
          (name == "pt_BR" && language.compare(0, 2, "pt") == 0))
        {
          chosen = i;
          found = true;
        }
      }
      if (found || language != "C")
      {
        break;
      }
    }
  }
  return table[chosen][id];
}
}

#endif
