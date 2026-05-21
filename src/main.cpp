#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget w;

    QHBoxLayout layout(&w);

    QTableWidget table;
    layout.addWidget(&table, 2);

    constexpr int row_count = 20;
    constexpr int column_count = 4;

    table.setRowCount(row_count);
    table.setColumnCount(column_count);

    // table.setEditTriggers(QAbstractItemView::NoEditTriggers);
    table.setEditTriggers(QAbstractItemView::DoubleClicked);
    // table.setEditTriggers(QAbstractItemView::AllEditTriggers);

    // table.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table.horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table.setHorizontalHeaderLabels({"number 1", "number 2", "number 3", "number 4"});

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            table.setItem(i, j, new QTableWidgetItem(QString::number(i + 1 + j)));
        }
    }

    QTableWidget result_table;
    layout.addWidget(&result_table, 1);

    result_table.setRowCount(row_count);
    result_table.setColumnCount(1);

    auto update_row = [&](const int row) {
        int sum = 0;
        for (int j = 0; j < column_count; j++) {
            sum += table.item(row, j)->text().toInt();
        }
        result_table.setItem(row, 0, new QTableWidgetItem(QString::number(sum)));
    };

    for (int i = 0; i < row_count; i++) { update_row(i); }

    QObject::connect(&table, &QTableWidget::itemChanged, [&](const QTableWidgetItem *i) {
        const int updated_row = i->row();
        update_row(updated_row);
    });

    w.setWindowTitle("markdown editor");
    w.setMinimumSize(500, 500);
    w.show();

    return QApplication::exec();
}
