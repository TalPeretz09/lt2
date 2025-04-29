int main(int argc, char *argv[])
{
    if (argc != 3) { //Checking for a third argument from the function
        cerr << "ERR: Enter input and output file names" << endl;
        return 1;
    }
    process_data(argv[1], argv[2]);
    return 0;
}
