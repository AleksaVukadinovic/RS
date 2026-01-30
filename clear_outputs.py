import os

EXTENSIONS_TO_DELETE = {".out", ".o"}

def delete_output_files(path):
    for entry in os.listdir(path):
        full_path = os.path.join(path, entry)

        if os.path.isfile(full_path):
            _, ext = os.path.splitext(entry)
            if ext in EXTENSIONS_TO_DELETE:
                os.remove(full_path)
        elif os.path.isdir(full_path):
            delete_output_files(full_path)

if __name__ == "__main__":
    print("Deleting leftover files...")
    delete_output_files(".")
    print("Deletion successful")
