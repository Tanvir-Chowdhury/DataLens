// TableViewer.h

#include <QObject>
#include <QWidget>
#include <QString>
#include <qtmetamacros.h>
#include <string>

class TableViewer : public QWidget {
  Q_OBJECT;
public:
    TableViewer(const QString &csvFileName, const std::string &dataFolder, QWidget *parent = nullptr);

private:
    void setupTable(const QString &csvFileName, const std::string &dataFolder);
};

