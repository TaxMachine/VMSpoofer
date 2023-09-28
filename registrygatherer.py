import winreg
import threading


def append_to_file(file, data):
    with open(file, "a") as f:
        f.write(data + "\n")


def search_registry(subkey, search_terms):
    for v in range(1024):
        try:
            name, value_type, value = winreg.EnumValue(subkey, v)
            if value_type != winreg.REG_SZ or value_type != winreg.REG_EXPAND_SZ:
                pass
            for term in search_terms:
                if (term in str(value).lower() or
                        term in str(name).lower() or
                        term in str(subkey).lower()):
                    print(f"Found {term} in {name} : {value}")
                    append_to_file("registry.txt", f"{name} : {value}")

        except WindowsError:
            pass


def enumerate_registry(key, search_terms):
    for i in range(1024):
        try:
            subkey_name = winreg.EnumKey(key, i)
            subkey = winreg.OpenKey(key, subkey_name)
            #print(f"Enumerating: {subkey_name}")
            threading.Thread(target=search_registry,
                             args=(subkey, search_terms)).start()
            enumerate_registry(subkey, search_terms)
        except WindowsError:
            pass


search_terms = ["vmware", "virtualbox"]

key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, "")

enumerate_registry(key, search_terms)

key.Close()
