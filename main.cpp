#include <string>
#include <iostream>
#include <fstream>

#include <windows.h>

using namespace std;

int DisplayPeripherals(){
	cout << "USB Device Lister." << endl;

    UINT nDevices = 0;
    GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST));

    if (nDevices < 1){
        cout << "ERR: 0 Devices?";
        cin.get();
        return 0;
    }

    PRAWINPUTDEVICELIST pRawInputDeviceList;
    pRawInputDeviceList = new RAWINPUTDEVICELIST[sizeof(RAWINPUTDEVICELIST) * nDevices];

    if (pRawInputDeviceList == NULL){
        cout << "ERR: Could not allocate memory for Device List, raw variable is null\n";
        cin.get();
        return 0;
    }

    int nResult;
    nResult = GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST));

    if (nResult < 0){
        delete[] pRawInputDeviceList;

        cout << "ERR: Could not get device list.";
        cin.get();
        return 0;
    }

    for (UINT i = 0; i < nDevices; i++){

        UINT nBufferSize = 0;

        nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, 
            RIDI_DEVICENAME,                
            NULL,                           
            &nBufferSize);                 

        if (nResult < 0){
            cout << "ERR: Unable to get Device Name character count.. Moving to next device." << endl << endl;
            continue;
        }

        WCHAR* wcDeviceName = new WCHAR[nBufferSize + 1];

        if (wcDeviceName == NULL){
            cout << "ERR: Unable to allocate memory for Device Name.. Moving to next device." << endl << endl;
            continue;
        }

        nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, 
            RIDI_DEVICENAME,                
            wcDeviceName,                   
            &nBufferSize);                 

        if (nResult < 0){
            cout << "ERR: Unable to get Device Name.. Moving to next device." << endl << endl;
            delete[] wcDeviceName;
            continue;
        }

        // Set Device Info & Buffer Size
        RID_DEVICE_INFO rdiDeviceInfo;
        rdiDeviceInfo.cbSize = sizeof(RID_DEVICE_INFO);
        nBufferSize = rdiDeviceInfo.cbSize;

        // Get Device Info
        nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice,
            RIDI_DEVICEINFO,
            &rdiDeviceInfo,
            &nBufferSize);

        if (nResult < 0){
            cout << "ERR: Unable to read Device Info.. Moving to next device." << endl << endl;
            continue;
        }

        // Mouse
        if (rdiDeviceInfo.dwType == RIM_TYPEMOUSE){
            cout << endl << "Displaying device " << i + 1 << " information. (MOUSE)" << endl;
            wcout << L"Device Name: " << wcDeviceName << endl;
            cout << "Mouse ID: " << rdiDeviceInfo.mouse.dwId << endl;
            cout << "Mouse buttons: " << rdiDeviceInfo.mouse.dwNumberOfButtons << endl;
            cout << "Mouse sample rate (Data Points): " << rdiDeviceInfo.mouse.dwSampleRate << endl;
            if (rdiDeviceInfo.mouse.fHasHorizontalWheel){
                cout << "Mouse has horizontal wheel" << endl;
            }
            else{
                cout << "Mouse does not have horizontal wheel" << endl;
            }
        }

        // Keyboard
        else if (rdiDeviceInfo.dwType == RIM_TYPEKEYBOARD){
            cout << endl << "Displaying device " << i + 1 << " information. (KEYBOARD)" << endl;
            wcout << L"Device Name: " << wcDeviceName << endl;
            cout << "Keyboard mode: " << rdiDeviceInfo.keyboard.dwKeyboardMode << endl;
            cout << "Number of function keys: " << rdiDeviceInfo.keyboard.dwNumberOfFunctionKeys << endl;
            cout << "Number of indicators: " << rdiDeviceInfo.keyboard.dwNumberOfIndicators << endl;
            cout << "Number of keys total: " << rdiDeviceInfo.keyboard.dwNumberOfKeysTotal << endl;
            cout << "Type of the keyboard: " << rdiDeviceInfo.keyboard.dwType << endl;
            cout << "Subtype of the keyboard: " << rdiDeviceInfo.keyboard.dwSubType << endl;
        }

        else {
            cout << endl << "Displaying device " << i + 1 << " information. (HID)" << endl;
            wcout << L"Device Name: " << wcDeviceName << endl;
            cout << "Vendor Id:" << rdiDeviceInfo.hid.dwVendorId << endl;
            cout << "Product Id:" << rdiDeviceInfo.hid.dwProductId << endl;
            cout << "Version No:" << rdiDeviceInfo.hid.dwVersionNumber << endl;
            cout << "Usage for the device: " << rdiDeviceInfo.hid.usUsage << endl;
            cout << "Usage Page for the device: " << rdiDeviceInfo.hid.usUsagePage << endl;
        }

        delete[] wcDeviceName;
    }

    delete[] pRawInputDeviceList;

    cout << endl << "Finnished.";
    cin.get();

    return 0;
}

const char* VARIABLE(const char* value){

	if(value == NULL){
		return "please insert a valid variable name";
	}

	const char* env_p = std::getenv(value);

	if(env_p){
		string varname = value;
		cout << varname +" is: " << env_p << '\n';
   		return env_p;
	}else{
		const char* result = "NULL";
		return result;
	}
}

bool WriteFile(string name, string format){

	fstream myfile;
	string entire_name;

	entire_name = name + "." + format;

	myfile.open(entire_name, ios::out);

	if(!myfile){
		return false;
	}else{
		myfile << "PATH vairable\n";
		myfile << VARIABLE("PATH");

		myfile << "\n\n";

		myfile << "OS variable\n";
		myfile << VARIABLE("OS");

		myfile.close();

		return true;
	}
}

int main() {
	//bool state = false;
	//state = WriteFile("new_file", "txt");

	//if(state == true){
	//	cout << "file created successfully";
	//}else{
	//	cout << "file not created";
	//}

	DisplayPeripherals();
	
    return 0;
}