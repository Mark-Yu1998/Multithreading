
#include <fstream>
#include <iostream>

#define SIZE 20
#define PEN 100
#define PAPER 200
#define LAPTOP 15
#define TONER 40

using namespace std;

int pen = 100;
int paper = 200;
int toner = 40;
int laptop = 15;
const char *FILENAME = "Sales";
pthread_mutex_t mutex_Inven;

void *process(void *args)
{
    // pthread_mutex_lock(&mutex_Inven);
    ifstream *inFile = ((ifstream *)(args));
    int *count = new int;
    *count = 0;
    string item;

    while ((*inFile) >> item)
    {
        (*count)++;

        if (!item.compare("pen"))
        {
            pthread_mutex_lock(&mutex_Inven);
            if (!pen)
            {
                pen = PEN;
            }
            pen--;
            pthread_mutex_unlock(&mutex_Inven);
        }

        if (!item.compare("paper"))
        {
            pthread_mutex_lock(&mutex_Inven);
            if (!paper)
            {
                paper = PAPER;
            }

            paper--;
            pthread_mutex_unlock(&mutex_Inven);
        }

        if (!item.compare("toner"))
        {
            pthread_mutex_lock(&mutex_Inven);

            if (!toner)
            {
                toner = TONER;
            }

            toner--;
            pthread_mutex_unlock(&mutex_Inven);
        }

        if (!item.compare("laptop"))
        {
            pthread_mutex_lock(&mutex_Inven);
            if (!laptop)
            {
                laptop = LAPTOP;
            }

            laptop--;
            pthread_mutex_unlock(&mutex_Inven);
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    pthread_t threads[SIZE];
    pthread_mutex_init(&mutex_Inven, NULL);
    ifstream *addr[SIZE];
    int total_sales = 0;
    for (int i = 0; i < SIZE; i++)
    {
        ifstream *inFile = new ifstream;
        addr[i] = inFile;
        string path = (FILENAME + to_string(i + 1) + ".txt");

        inFile->open(path);

        if (!inFile->is_open())
        {
            cout << "Unable to open file" << endl;
            return -1;
        }

        if (0 != pthread_create(&threads[i], NULL, process, inFile))
        {
            cout << "Not successful" << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        void *count;
        if (pthread_join(threads[i], &count) != 0)
        {
            cout << "Cannot join" << endl;
            return -1;
        }
        total_sales += *(int *)count;
        delete (int *)count;
        addr[i]->close();
        delete addr[i];
    }

    cout << "Pen: " << pen << endl;
    cout << "Paper: " << paper << endl;
    cout << "Toner: " << toner << endl;
    cout << "Laptop: " << laptop << endl;
    cout << "Total Sales: " << total_sales << endl;

    //Delete all the streams
    return 0;
}
