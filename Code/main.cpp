int main(int argc, char *argv[])
{
    if (argc != 3) {
        cerr << "Error: Please provide input and output filenames" << endl;
        return 1;
    }
    process_data(argv[1], argv[2]);
    return 0;
}
