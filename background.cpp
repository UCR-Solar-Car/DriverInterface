#include "background.h"

Background::Background() {}

void Background::darkTheme() {
  QFile f( ":qdarkstyle/style.qss" );

  if ( !f.exists() ) {
    qWarning() << "Unable to set dark stylesheet, file not found";
  } else {
    f.open( QFile::ReadOnly | QFile::Text );
    QTextStream ts( &f );
    qApp->setStyleSheet(ts.readAll());
  }
}
