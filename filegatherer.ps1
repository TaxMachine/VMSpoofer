function GetVMWareFiles {
    $windowsfiles = Get-ChildItem -Path C:\Windows -Recurse -File | Where-Object {
        $_.Name -contains "vmware" -or
                $_.Name -contains "vpx" -or
                $_.Name -contains "vm" -or
                $_.Name -contains "vpxa" -or
                $_.Name -contains "vpxd" -or
                $_.Name -contains "virtual"
    }
    return $windowsfiles
}

function GetVBoxFiles {
    $windowsfiles = Get-ChildItem -Path C:\Windows -Recurse -File | Where-Object {
        $_.Name -contains "vbox" -or
                $_.Name -contains "virtual" -or
                $_.Name -contains "box" -or
                $_.Name -contains "vdi" -or
                $_.Name -contains "vmdk" -or
                $_.Name -contains "vhd"
    }
    return $windowsfiles
}

function GetDefaultWindowsFiles {
    return Get-ChildItem -Path C:\Windows -Recurse -File
}

function Main {
    $vm = Read-Host -Prompt "Are you running this on a VM? (y/n)"
    if ($vm -eq "y") {
        $files = GetDefaultWindowsFiles -join "`n"
        $files | Copy-Item -Destination .\WindowsFiles.txt
    } else
    {
        $vmwfiles += GetVMWareFiles -join "`n"
        $vboxfiles += GetVBoxFiles -join "`n"

        $vmwfiles | Copy-Item -Destination .\VMWareFiles.txt
        $vboxfiles | Copy-Item -Destination .\VBoxFiles.txt
    }
}