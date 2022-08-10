#include "background.h"

Background::Background() {}

void Background::dark_theme() {
  qApp->setStyle(QStyleFactory::create("Fusion"));

  QPalette dark_palette;
  dark_palette.setColor(QPalette::Window, QColor(40,40,40));
  dark_palette.setColor(QPalette::WindowText, Qt::white);
  dark_palette.setColor(QPalette::Base, QColor(25,25,25));
  dark_palette.setColor(QPalette::AlternateBase, QColor(40,40,40));
  dark_palette.setColor(QPalette::ToolTipBase, Qt::white);
  dark_palette.setColor(QPalette::ToolTipText, Qt::white);
  dark_palette.setColor(QPalette::Text, Qt::white);
  dark_palette.setColor(QPalette::Button, QColor(40,40,40));
  dark_palette.setColor(QPalette::ButtonText, Qt::white);
  dark_palette.setColor(QPalette::BrightText, Qt::red);
  dark_palette.setColor(QPalette::Link, QColor(42, 130, 218));

  dark_palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  dark_palette.setColor(QPalette::HighlightedText, Qt::black);
  
  qApp->setPalette(dark_palette);

  qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}
