#ifndef UI_AVATAR_H
#define UI_AVATAR_H

#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QWidget>

#include "Theme.h"

class Avatar : public QWidget
{
	Q_OBJECT

	Q_PROPERTY(QColor textColor WRITE setTextColor READ textColor)
	Q_PROPERTY(QColor backgroundColor WRITE setBackgroundColor READ backgroundColor)

public:
	explicit Avatar(QWidget *parent = 0);
	~Avatar();

	void setBackgroundColor(const QColor &color);
	void setIcon(const QIcon &icon);
	void setImage(const QImage &image);
	void setLetter(const QChar &letter);
	void setSize(int size);
	void setTextColor(const QColor &color);

	QColor backgroundColor() const;
	QColor textColor() const;
	int size() const;

	QSize sizeHint() const override;

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	void init();

	ui::AvatarType type_;
	QChar letter_;
	QColor background_color_;
	QColor text_color_;
	QIcon icon_;
	QImage image_;
	QPixmap pixmap_;
	int size_;
};

#endif  // UI_AVATAR_H
