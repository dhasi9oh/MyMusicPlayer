
#include "const.h"

QString gate_url_prefix = "";

std::function<QString(QString)> xorString =
[](QString input) {
	QString result = input; // ����ԭʼ�ַ������Ա�����޸�
	int length = input.length(); // ��ȡ�ַ����ĳ���
	length = length % 255;
	for (int i = 0; i < length; ++i) {
		// ��ÿ���ַ�����������
		// ע�⣺��������ַ�����ASCII�����ֱ��ת��ΪQChar
		result[i] = QChar(static_cast<ushort>(input[i].unicode() ^ static_cast<ushort>(length)));
	}
	return result;
	};

//����һ����ʧ��رյ���ʾ����
std::function<void(const QString&, bool)> showTip =
[](const QString& str, bool flag)
	{
		auto ptr = TinyWidgetLibrary::MessageBoxHint();
		ptr.setText(str);
		ptr.setFrameColor(flag ? QColor(0, 102, 180) : Qt::red);
		ptr.show();
		emit ptr.readyShow();
	};

//��ʱ�䣨s��ת��Ϊxx:xx����ʽ
std::function<QString(int)> transfTimeStr =
[](int duration)-> QString
	{
		QString m(QString::number(duration / 60));
		QString s(QString::number(duration % 60));

		if (m.size() < 2) {
			m.push_front("0");
		}

		if (s.size() < 2) {
			s.push_front("0");
		}

		return m + ":" + s;
	};

//��ʱ��xx:xx����ʽת��Ϊʱ�䳤��
std::function<int(const QString&)> transfTimeInt =
[](const QString& str)->int
	{
		int idx = str.indexOf(":");
		QString m(str.left(idx));
		QString s(str.right(str.size() - idx));

		return m.toInt() * 60 + s.toInt();
	};

//��QListWidget�в���һ��QListWidgetItem��widget
std::function<QWidget* (QListWidget*, QListWidgetItem*)> findItem =
[](QListWidget* list_widget_ptr, QListWidgetItem* item_ptr)->QWidget*
	{
		for (int i = 0; i < list_widget_ptr->count(); i++) {
			if (list_widget_ptr->item(i) == item_ptr) {
				return list_widget_ptr->itemWidget(item_ptr);
			}
		}
		return nullptr;
	};

//��QListWidget�в���һ��widget��QListWidgetItem
std::function<QListWidgetItem* (QListWidget*, QWidget*)> findWidget =
[](QListWidget* list_widget_ptr, QWidget* widget_ptr)->QListWidgetItem*
	{
		for (int i = 0; i < list_widget_ptr->count(); i++) {
			if (list_widget_ptr->itemWidget(list_widget_ptr->item(i)) == widget_ptr) {
				return list_widget_ptr->item(i);
			}
		}
		return nullptr;
	};

bool operator<(ReqId a, ReqId b)
{
	return static_cast<int>(a) < static_cast<int>(b);
}