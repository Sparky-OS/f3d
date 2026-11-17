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
  DepthNotOffered,
  DepthNotDelivered,
  DepthNotReadable,
  Count
};

inline const char* Text(Id id)
{
  static const char* const table[][Count] = {
    // en
    { "Enable 3D", "Display Settings", "Display Settings could not be opened: kcmshell6 was not found",
      "3D could not be enabled: this display offers no stereo window",
      "3D depth: this desktop offers no depth limits, so both eyes show the same picture", "3D depth: the desktop has not delivered the depth limits yet, both eyes show the same picture for now", "3D depth: this window cannot read the desktop's depth limits, so both eyes show the same picture" },
    // pl
    { "Włącz 3D", "Ustawienia ekranu", "Nie można otworzyć ustawień ekranu: nie znaleziono kcmshell6",
      "Nie można włączyć 3D: ten ekran nie udostępnia okna stereo",
      "Głębia 3D: ten pulpit nie podaje limitów głębi, więc oba oczy widzą ten sam obraz", "Głębia 3D: pulpit nie przekazał jeszcze limitów głębi, na razie oba oczy widzą ten sam obraz", "Głębia 3D: to okno nie może odczytać limitów głębi pulpitu, więc oba oczy widzą ten sam obraz" },
    // pt_BR
    { "Ativar 3D", "Configurações de tela", "Não foi possível abrir as configurações de tela: kcmshell6 não foi encontrado",
      "Não foi possível ativar o 3D: esta tela não oferece uma janela estéreo",
      "Profundidade 3D: este desktop não oferece limites de profundidade, então os dois olhos veem a mesma imagem", "Profundidade 3D: o desktop ainda não entregou os limites de profundidade, por enquanto os dois olhos veem a mesma imagem", "Profundidade 3D: esta janela não consegue ler os limites de profundidade do desktop, então os dois olhos veem a mesma imagem" },
    // fr
    { "Activer la 3D", "Paramètres d’affichage", "Impossible d’ouvrir les paramètres d’affichage : kcmshell6 est introuvable",
      "Impossible d’activer la 3D : cet affichage ne propose pas de fenêtre stéréo",
      "Profondeur 3D : ce bureau n’offre pas de limites de profondeur, les deux yeux voient donc la même image", "Profondeur 3D : le bureau n’a pas encore transmis les limites de profondeur, les deux yeux voient la même image pour l’instant", "Profondeur 3D : cette fenêtre ne peut pas lire les limites de profondeur du bureau, les deux yeux voient donc la même image" },
    // de
    { "3D aktivieren", "Anzeigeeinstellungen", "Die Anzeigeeinstellungen konnten nicht geöffnet werden: kcmshell6 wurde nicht gefunden",
      "3D konnte nicht aktiviert werden: dieser Bildschirm bietet kein Stereo-Fenster",
      "3D-Tiefe: Dieser Desktop bietet keine Tiefengrenzen, deshalb sehen beide Augen dasselbe Bild", "3D-Tiefe: Der Desktop hat die Tiefengrenzen noch nicht geliefert, beide Augen sehen vorerst dasselbe Bild", "3D-Tiefe: Dieses Fenster kann die Tiefengrenzen des Desktops nicht lesen, deshalb sehen beide Augen dasselbe Bild" },
    // es
    { "Activar 3D", "Configuración de pantalla", "No se pudo abrir la configuración de pantalla: no se encontró kcmshell6",
      "No se pudo activar el 3D: esta pantalla no ofrece una ventana estéreo",
      "Profundidad 3D: este escritorio no ofrece límites de profundidad, así que los dos ojos ven la misma imagen", "Profundidad 3D: el escritorio aún no ha entregado los límites de profundidad, por ahora los dos ojos ven la misma imagen", "Profundidad 3D: esta ventana no puede leer los límites de profundidad del escritorio, así que los dos ojos ven la misma imagen" },
    // ja
    { "3Dを有効にする", "ディスプレイ設定", "ディスプレイ設定を開けませんでした: kcmshell6 が見つかりません",
      "3Dを有効にできませんでした: このディスプレイはステレオウィンドウを提供していません",
      "3D奥行き: このデスクトップは奥行きの上限を提供しないため、両目に同じ画像を表示します", "3D奥行き: デスクトップがまだ奥行きの上限を渡していないため、今は両目に同じ画像を表示します", "3D奥行き: このウィンドウはデスクトップの奥行きの上限を読み取れないため、両目に同じ画像を表示します" },
    // ko
    { "3D 켜기", "디스플레이 설정", "디스플레이 설정을 열 수 없습니다: kcmshell6을 찾을 수 없습니다",
      "3D를 켤 수 없습니다: 이 디스플레이는 스테레오 창을 제공하지 않습니다",
      "3D 깊이: 이 데스크톱은 깊이 한계를 제공하지 않아 두 눈에 같은 화면을 보여 줍니다", "3D 깊이: 데스크톱이 아직 깊이 한계를 전달하지 않아 지금은 두 눈에 같은 화면을 보여 줍니다", "3D 깊이: 이 창은 데스크톱의 깊이 한계를 읽을 수 없어 두 눈에 같은 화면을 보여 줍니다" },
    // zh_CN
    { "启用 3D", "显示设置", "无法打开显示设置：找不到 kcmshell6", "无法启用 3D：此显示器不提供立体窗口",
      "3D 深度：此桌面未提供深度限制，因此两眼显示相同的画面", "3D 深度：桌面尚未提供深度限制，暂时两眼显示相同的画面", "3D 深度：此窗口无法读取桌面的深度限制，因此两眼显示相同的画面" },
    // zh_TW
    { "啟用 3D", "顯示設定", "無法開啟顯示設定：找不到 kcmshell6", "無法啟用 3D：此顯示器不提供立體視窗",
      "3D 深度：此桌面未提供深度限制，因此兩眼顯示相同的畫面", "3D 深度：桌面尚未提供深度限制，暫時兩眼顯示相同的畫面", "3D 深度：此視窗無法讀取桌面的深度限制，因此兩眼顯示相同的畫面" },
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
