#ifndef PARISOLYMPICSANALYSIS_H
#define PARISOLYMPICSANALYSIS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include <QPixmap>
#include <QStringList>

class ParisOlympicsAnalysis : public QWidget {
  Q_OBJECT

public:
  explicit ParisOlympicsAnalysis(QWidget *parent = nullptr);

protected:
  void resizeEvent(QResizeEvent *event) override;

private slots:
  void showNextImage();

private:
  void loadImagesFromFolder();
  void showImage(int index);

  QLabel *imageLabel;
  QLabel *headingLabel; // Heading label to display image name
  QPixmap currentImage;
  QStringList images;
  QString imageFolder;
  int currentImageIndex;
};

#endif // PARISOLYMPICSANALYSIS_H

