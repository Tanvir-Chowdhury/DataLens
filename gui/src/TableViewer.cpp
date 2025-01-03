#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "Database.h"

class TableViewer : public QWidget {
public:
    TableViewer(const QString &csvFileName, const std::string &dataFolder, QWidget *parent = nullptr);

private:
    void setupTable(const QString &csvFileName, const std::string &dataFolder);
};

TableViewer::TableViewer(const QString &csvFileName, const std::string &dataFolder, QWidget *parent)
    : QWidget(parent) {
    setupTable(csvFileName, dataFolder);
}

void TableViewer::setupTable(const QString &csvFileName, const std::string &dataFolder) {
    Database db;
    db.loadDatabase(dataFolder);

    LinkedList *table = db.getTable(csvFileName.toStdString());
    if (!table) {
        qCritical() << "Table not found for file:" << csvFileName;
        return;
    }

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *heading = new QLabel(QString("Viewing Table: %1").arg(csvFileName));
    heading->setStyleSheet("font-size: 16px; font-weight: bold; margin-bottom: 10px;");
    layout->addWidget(heading);

    QTableWidget *tableWidget = new QTableWidget(this);

    const auto &columns = table->columns;
    tableWidget->setColumnCount(static_cast<int>(columns.size()));
    QStringList headers;
    for (const auto &column : columns) {
        headers << QString::fromStdString(column);
    }
    tableWidget->setHorizontalHeaderLabels(headers);

    Node *current = table->getHead();
    int row = 0;
    while (current) {
        tableWidget->insertRow(row);
        for (size_t col = 0; col < current->data.size(); ++col) {
            tableWidget->setItem(row, static_cast<int>(col),
                                 new QTableWidgetItem(QString::fromStdString(current->data[col])));
        }
        current = current->next;
        ++row;
    }

    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    tableWidget->resizeColumnsToContents();
    tableWidget->resizeRowsToContents();

    layout->addWidget(tableWidget);

    this->resize(800, 600);
}
