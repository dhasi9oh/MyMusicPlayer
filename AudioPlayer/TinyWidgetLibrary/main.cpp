
#include <iostream>
#include <qapplication.h>
#include "Buttons/CheckableButton/SwitchButton.h"
#include "Buttons/CheckableButton/RadioButton.h"
#include "Buttons/CheckableButton/CheckButton.h"
#include "Buttons/CheckableButton/ToggleButton.h"
#include "Buttons/RectangleButton/StandardButton.h"

#include "PopupBox/SizeFixedDialog.h"
#include "PopupBox/FloatWindow.h"
#include "PopupBox/MessageBoxHint.h"

#include "Progress/Slider.h"
#include "TextBox/TextBox.h"

#include <qdialog.h>
#include <qslider.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget w;
	QPushButton button(&w);
	TinyWidgetLibrary::PointFixedWidget s(&button);
	w.resize(480, 640);
	button.move(100, 100);
	QObject::connect(&button, &QPushButton::clicked, [&]{s.setVisible(!s.isVisible());});
	w.show();
    return a.exec();
}