#include <iostream>
#include <string>
#include <fstream> // for txt io
#include <vector>  // for array and matrix
#include <chrono>  // for time
#include <random>
using namespace std;

// Mengembalikan nilai horizontal dari input txt
string getforhor(string in);

// Mengembalikan nilai vertikal dari input txt
string getforver(string in);

// Mengembalikan nilai baris matrix yang diakses sebagai array of tokens
vector<string> getperrow(string in, int how, int horizon);

// Mengembalikan jumlah token yang terdapat dalam string dari input txt
int findSize(string in);

// Mengembalikan jumlah slot kosong dalam array of tokens
int findEmpty(vector<string> in, int size);

// fungsi Stringmatching, mengembalikan nilai true juka terdapat string test
// sebagai substring dari check
bool inHere(vector<string> test, vector<string> check);

// I. S. in terdefinisi
// F. S. in akan tercetak di layar dengan tiap elemen dibatasi spasi
void printBufferv2(vector<string> in);

// Mengembalikan nilai true jika file terdapat pada path yang diinginkan
bool checkFExistence(string path);

// Mengembalikan nilai horizontal dari input txt
string getforhor(string in)
{
    int counter = 0;
    string ret;
    while (counter < in.length())
    {
        if (in[counter] != ' ')
        {
            counter++;
        }
        else
        {
            ret.append(in, 0, counter);
            break;
        }
    }
    return ret;
}

// Mengembalikan nilai vertikal dari input txt
string getforver(string in)
{
    int counter = 0;
    string ret;
    bool take = false;
    while (counter < in.length())
    {
        if (in[counter] != ' ' && !take)
        {
            counter++;
        }
        else if (in[counter] == ' ')
        {
            take = true;
            counter++;
        }
        else if (take)
        {
            ret.append(in.begin() + counter, in.end());
            break;
        }
    }
    return ret;
}

// Mengembalikan nilai baris matrix yang diakses sebagai array of tokens
vector<string> getperrow(string in, int how, int horizon)
{
    int counter = 0;
    int where = 0;
    int loc = 0;
    vector<string> ret(horizon);
    string current;
    while (counter < in.length())
    {
        if (in[counter] != ' ')
        {
            current.append(in, where, 2);
            where += 3;
            counter += 3;
            ret[loc] = current;
            loc++;
            current = "";
        }
        if (loc == how - 1)
        {
            current.append(in, where, 2);
            ret[loc] = current;
            loc++;
            break;
        }
    }
    return ret;
}

// Mengembalikan jumlah token yang terdapat dalam string dari input txt
int findSize(string in)
{
    int ret = 1;
    for (int i = 0; i < in.length(); i++)
    {
        if (in[i] == ' ')
        {
            ret++;
        }
    }
    return ret;
}

// Mengembalikan jumlah slot kosong dalam array of tokens
int findEmpty(vector<string> in, int size)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == "XX")
        {
            return size - i;
        }
    }
    return 0;
}

// fungsi Stringmatching, mengembalikan nilai true juka terdapat string test
// sebagai substring dari check
bool inHere(vector<string> test, vector<string> check)
{
    string strCheck;
    for (const auto &str : check)
    {
        strCheck += str;
    }

    string strTest;
    for (const auto &str : test)
    {
        strTest += str;
    }

    return strCheck.find(strTest) != string::npos;
}

void printBuffer(vector<string> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] + ' ';
    }
    cout << endl;
}

// I. S. in terdefinisi
// F. S. in akan tercetak di layar dengan tiap elemen dibatasi spasi
void printBufferv2(vector<string> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] != "XX")
        {
            cout << in[i] + ' ';
        }
    }
    cout << endl;
}

// Mengembalikan nilai true jika file terdapat pada path yang diinginkan
bool checkFExistence(string path)
{
    ifstream file(path);
    return file.good();
}

// FUNGSI UTAMA
void recFind(vector<vector<string>> matric, vector<vector<string>> tempmatric, vector<int> curh, vector<int> curv, vector<string> curbuff, vector<vector<string>> tofind, vector<int> rew, int slot, int &max, vector<int> &finh, vector<int> &finv, vector<string> &maxbuff, int loch, int locv, int dir)
{
    // BASIS
    if (slot <= 0)
    {
        // Calculation
    }

    // Recursion
    else
    {
        // Calculation
        if (dir == 99) // Initial
        {
            for (int i1 = 0; i1 < tempmatric[0].size(); i1++)
            {
                vector<vector<string>> temptemp1(tempmatric.size(), vector<string>(tempmatric[0].size()));
                temptemp1 = tempmatric;
                vector<string> prevbuff1(curbuff.size());
                prevbuff1 = curbuff;
                vector<int> prevh1(curbuff.size());
                prevh1 = curh;
                vector<int> prevv1(curbuff.size());
                prevv1 = curv;
                int prevloch = loch;
                int prevlocv = locv;
                int prevslot = slot;

                tempmatric = matric;
                curbuff[0] = tempmatric[0][i1];
                tempmatric[0][i1] = "XX";

                // Setup
                loch = i1;
                locv = 0;
                curh[curbuff.size() - slot] = i1;
                curv[curbuff.size() - slot] = 0;
                slot -= 1;

                // Stringmatching
                int points = 0;
                for (int i2 = 0; i2 < tofind.size(); i2++)
                {
                    if (inHere(tofind[i2], curbuff))
                    {
                        points += rew[i2];
                        return;
                    }
                }

                // Compare to Highest
                if (points > max)
                {
                    maxbuff = curbuff;
                    finh = curh;
                    finv = curv;
                    max = points;
                    break;
                }

                // printBuffer(curbuff);

                // Next Recursion
                dir = 1;
                recFind(matric, tempmatric, curh, curv, curbuff, tofind, rew, slot, max, finh, finv, maxbuff, loch, locv, dir);

                tempmatric = temptemp1;
                curh = prevh1;
                curv = prevv1;
                curbuff = prevbuff1;
                slot = prevslot;
                loch = prevloch;
                locv = prevlocv;
            }
        }

        else if (dir == 0) // Horizontal
        {
            for (int i3 = 0; i3 < tempmatric[0].size(); i3++)
            {
                vector<vector<string>> temptemp2(tempmatric.size(), vector<string>(tempmatric[0].size()));
                temptemp2 = tempmatric;
                vector<string> prevbuff2(curbuff.size());
                prevbuff2 = curbuff;
                vector<int> prevh2(curbuff.size());
                prevh2 = curh;
                vector<int> prevv2(curbuff.size());
                prevv2 = curv;
                int prevloch = loch;
                int prevlocv = locv;
                int prevslot = slot;

                if (tempmatric[locv][i3] != "XX")
                {
                    curbuff[curbuff.size() - slot] = tempmatric[locv][i3];
                    tempmatric[locv][i3] = "XX";

                    // Setup
                    loch = i3;
                    // locv = locv, locv stays
                    curh[curbuff.size() - slot] = i3;
                    curv[curbuff.size() - slot] = locv;
                    slot -= 1;

                    // Stringmatching
                    int points = 0;
                    for (int i4 = 0; i4 < tofind.size(); i4++)
                    {
                        if (inHere(tofind[i4], curbuff))
                        {
                            points += rew[i4];
                        }
                    }

                    // Compare to Highest
                    if (points > max)
                    {
                        maxbuff = curbuff;
                        finh = curh;
                        finv = curv;
                        max = points;

                        break;
                    }

                    // printBuffer(curbuff);

                    // Next Recursion
                    int prevdir = dir;
                    dir = 1;
                    recFind(matric, tempmatric, curh, curv, curbuff, tofind, rew, slot, max, finh, finv, maxbuff, loch, locv, dir);

                    tempmatric = temptemp2;
                    curh = prevh2;
                    curv = prevv2;
                    curbuff = prevbuff2;
                    slot = prevslot;
                    loch = prevloch;
                    locv = prevlocv;
                }
            }
        }

        else if (dir == 1) // Vertical
        {
            for (int i5 = 0; i5 < tempmatric.size(); i5++)
            {
                vector<vector<string>> temptemp3(tempmatric.size(), vector<string>(tempmatric[0].size()));
                temptemp3 = tempmatric;
                vector<string> prevbuff3(curbuff.size());
                prevbuff3 = curbuff;
                vector<int> prevh3(curbuff.size());
                prevh3 = curh;
                vector<int> prevv3(curbuff.size());
                prevv3 = curv;
                int prevloch = loch;
                int prevlocv = locv;
                int prevslot = slot;

                if (tempmatric[i5][loch] != "XX")
                {
                    curbuff[curbuff.size() - slot] = tempmatric[i5][loch];
                    tempmatric[i5][loch] = "XX";

                    // Setup
                    // loch = loch, loch stays
                    locv = i5;
                    curh[curbuff.size() - slot] = loch;
                    curv[curbuff.size() - slot] = i5;
                    slot -= 1;

                    // Stringmatching
                    int points = 0;
                    for (int i6 = 0; i6 < tofind.size(); i6++)
                    {
                        if (inHere(tofind[i6], curbuff))
                        {
                            points += rew[i6];
                        }
                    }

                    // Compare to Highest
                    if (points > max)
                    {
                        maxbuff = curbuff;
                        finh = curh;
                        finv = curv;
                        max = points;
                        break;
                    }

                    // printBuffer(curbuff);

                    // Next Recursion
                    int prevdir = dir;
                    dir = 0;
                    recFind(matric, tempmatric, curh, curv, curbuff, tofind, rew, slot, max, finh, finv, maxbuff, loch, locv, dir);

                    tempmatric = temptemp3;
                    curh = prevh3;
                    curv = prevv3;
                    curbuff = prevbuff3;
                    slot = prevslot;
                    loch = prevloch;
                    locv = prevlocv;
                    dir = prevdir;
                }
            }
        }
    }
}

// MAIN PROGRAM
int main()
{
    int method = 0;
    cout << "========== WELCOME TO CYBERPUNK BREACH PROTOCOL SOLVER ==========" << endl;
    cout << "1. TXT input." << endl;
    cout << "2. CLI input." << endl;
    cout << "Select entry method: (1/2) ";
    cin >> method;

    string input;
    vector<string> dim(2);

    if (method == 1)
    {
        ifstream testcase;
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        string fileAdd = "../test/" + fileName + ".txt";

        while (!checkFExistence(fileAdd))
        {
            cout << "File does not exist, please enter an existing file" << endl;
            cout << "Enter file name: ";
            cin >> fileName;
            fileAdd = "../test/" + fileName + ".txt";
        }
        testcase.open(fileAdd);

        getline(testcase, input);

        const int a = stoi(input);
        vector<string> buffer(a);

        getline(testcase, input);
        dim[0] = getforhor(input);
        dim[1] = getforver(input);

        const int hor = stoi(dim[0]);
        const int ver = stoi(dim[1]);

        vector<vector<string>> matrix(ver, vector<string>(hor));

        for (int i = 0; i < ver; i++)
        {
            getline(testcase, input);
            matrix[i] = getperrow(input, hor, hor);
            for (int j = 0; j < hor; j++)
            {
                cout << matrix[i][j] + ' ';
            }
            cout << endl;
        }

        getline(testcase, input);
        const int seqnum = stoi(input);
        vector<vector<string>> sequences(seqnum);
        vector<int> rewards(seqnum);
        for (int i = 0; i < seqnum; i++)
        {
            getline(testcase, input);
            int tempsize = findSize(input);
            sequences[i].resize(tempsize);
            sequences[i] = getperrow(input, tempsize, tempsize);

            getline(testcase, input);
            rewards[i] = stoi(input);

            for (int j = 0; j < tempsize; j++)
            {
                cout << sequences[i][j] + ' ';
            }
            cout << endl;
            cout << rewards[i] << endl;
        }

        // MAIN BRUTE FORCE ALGORITHM
        vector<vector<string>> tempmatrix(ver, vector<string>(hor));
        tempmatrix = matrix;
        int avslot = 0;
        int maxval = 0;
        vector<int> finhor(a);
        vector<int> finver(a);
        vector<string> tempbuff(a, "XX");

        vector<int> currenth(a);
        vector<int> currentv(a);

        testcase.close();

        auto searchStart = chrono::high_resolution_clock::now();

        recFind(matrix, tempmatrix, currenth, currentv, tempbuff, sequences, rewards, a, maxval, finhor, finver, buffer, 0, 0, 99);

        auto searchEnd = chrono::high_resolution_clock::now();

        chrono::duration<double> timeTaken = searchEnd - searchStart;

        // Results
        cout << "======= COMPLETED =======" << endl;
        cout << maxval << endl;
        printBufferv2(buffer);
        if (maxval == 0)
        {
            cout << "NO SOLUTION FOUND" << endl;
        }
        else
        {
            for (int i = 0; i < a; i++)
            {
                if (buffer[i] != "XX")
                {
                    cout << finhor[i] + 1;
                    cout << ", ";
                    cout << finver[i] + 1 << endl;
                }
            }
        }

        cout << "Time taken: " << timeTaken.count() << "seconds." << endl;

        string confirm;
        string saveFile, saveFilefin;
        ofstream saveStream;

        cout << "Do you want to save the solution? (Y/N): ";
        cin >> confirm;
        if (confirm == "Y" || confirm == "y")
        {
            cout << "Enter your solution file name: ";
            cin >> saveFile;
            saveFilefin = "../test/" + saveFile + ".txt";

            if (checkFExistence(saveFilefin))
            {
                cout << "Filename exist, overwriting file" << endl;
            }
            else
            {
                cout << "Creating " << saveFile << ".txt" << endl;
            }

            saveStream.open(saveFilefin);

            if (!saveStream.is_open())
            {
                cerr << "Unable to open file" << endl;
                return 0;
            }

            // Output to file
            saveStream << to_string(maxval) << endl;
            if (maxval == 0)
            {
                saveStream << "NO SOLUTION FOUND" << endl;
            }
            else
            {
                for (int i = 0; i < buffer.size(); i++)
                {
                    if (buffer[i] != "XX")
                    {
                        saveStream << buffer[i] + ' ';
                    }
                }
                saveStream << endl;
                for (int i = 0; i < a; i++)
                {
                    saveStream << finhor[i] + 1;
                    saveStream << ", ";
                    saveStream << finver[i] + 1 << endl;
                }
            }

            saveStream << "Time taken: " << timeTaken.count() << " seconds." << endl;
        }
        else
        {
            // DO NOTHING
        }
    }
    else
    {
        int unique;
        int buff_size;
        int m_h, m_v;
        string temptoken;
        cout << "Enter unique token type amount: ";
        cin >> unique;
        vector<string> token_pool(unique);
        cout << "Enter tokens for the token pool: ";
        for (int i = 0; i < unique; i++)
        {
            cin >> temptoken;
            token_pool[i] = temptoken;
        }

        int min = 0;
        int max = unique - 1;

        cout << "Enter buffer size: ";
        cin >> buff_size;
        vector<string> buffer(buff_size);
        cout << "Enter matrix dimensions (horizontal vertical): ";
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                cin >> m_h;
            }
            else
            {
                cin >> m_v;
            }
        }

        vector<vector<string>> matrix(m_v, vector<string>(m_h));
        int rng;

        // RNG - 1 (token pool)
        random_device mach;
        mt19937 generator(mach());
        uniform_int_distribution<> rendo(min, max);

        for (int i = 0; i < m_v; i++)
        {
            for (int j = 0; j < m_h; j++)
            {
                rng = rendo(generator);
                matrix[i][j] = token_pool[rng];
                cout << matrix[i][j] + ' ';
            }
            cout << endl;
        }

        int seqnum;
        cout << "Enter target sequences amount: ";
        cin >> seqnum;

        vector<vector<string>> sequences(seqnum);
        vector<int> rewards(seqnum);

        int max_size;
        cout << "Enter maximum sequence length: ";
        cin >> max_size;

        // RNG - 2 (sequence length)
        random_device mach2;
        mt19937 generator2(mach2());
        uniform_int_distribution<> rendo2(2, max_size);

        for (int i = 0; i < seqnum; i++)
        {
            int tempsize = rendo2(generator2);
            sequences[i].resize(tempsize);
            rewards[i] = tempsize * 15;
            cout << "Target Sequence " << i + 1 << ": ";
            cout << "(Value: " << rewards[i] << ") " << endl;
            for (int j = 0; j < tempsize; j++)
            {
                rng = rendo(generator);
                sequences[i][j] = token_pool[rng];
                cout << sequences[i][j] + ' ';
            }
            cout << endl;
        }

        // MAIN BRUTE FORCE ALGORITHM
        vector<vector<string>> tempmatrix(m_v, vector<string>(m_h));
        tempmatrix = matrix;
        int avslot = 0;
        int maxval = 0;
        vector<int> finhor(buff_size);
        vector<int> finver(buff_size);
        vector<string> tempbuff(buff_size, "XX");

        vector<int> currenth(buff_size);
        vector<int> currentv(buff_size);

        auto searchStart = chrono::high_resolution_clock::now();

        recFind(matrix, tempmatrix, currenth, currentv, tempbuff, sequences, rewards, buff_size, maxval, finhor, finver, buffer, 0, 0, 99);

        auto searchEnd = chrono::high_resolution_clock::now();

        chrono::duration<double> timeTaken = searchEnd - searchStart;

        // Results
        cout << "======= COMPLETED =======" << endl;
        cout << maxval << endl;
        printBufferv2(buffer);

        if (maxval == 0)
        {
            cout << "NO SOLUTION FOUND" << endl;
        }
        else
        {
            for (int i = 0; i < buff_size; i++)
            {
                if (buffer[i] != "XX")
                {
                    cout << finhor[i] + 1;
                    cout << ", ";
                    cout << finver[i] + 1 << endl;
                }
            }
        }
        cout << "Time taken: " << timeTaken.count() << "seconds." << endl;

        string confirm;
        string saveFile, saveFilefin;
        ofstream saveStream;

        cout << "Do you want to save the solution? (Y/N): ";
        cin >> confirm;
        if (confirm == "Y" || confirm == "y")
        {
            cout << "Enter your solution file name: ";
            cin >> saveFile;
            saveFilefin = "../test/" + saveFile + ".txt";

            if (checkFExistence(saveFilefin))
            {
                cout << "Filename exist, overwriting file" << endl;
            }
            else
            {
                cout << "Creating " << saveFile << ".txt" << endl;
            }

            saveStream.open(saveFilefin);

            if (!saveStream.is_open())
            {
                cerr << "Unable to open file" << endl;
                return 0;
            }

            // Output to file
            saveStream << to_string(maxval) << endl;
            if (maxval == 0)
            {
                saveStream << "NO SOLUTION FOUND" << endl;
            }
            else
            {
                for (int i = 0; i < buffer.size(); i++)
                {
                    if (buffer[i] != "XX")
                    {
                        saveStream << buffer[i] + ' ';
                    }
                }
                saveStream << endl;
                for (int i = 0; i < buff_size; i++)
                {
                    saveStream << finhor[i] + 1;
                    saveStream << ", ";
                    saveStream << finver[i] + 1 << endl;
                }
            }

            saveStream << "Time taken: " << timeTaken.count() << " seconds." << endl;
        }
        else
        {
            // DO NOTHING
        }
    }
}
