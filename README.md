# Prototype

Make sure to only keep contents of the Classes and Resources folder in this repository.

**Important:**
Whenever there is a new class file (.cpp) make sure to include it in your *Android.mk* which can be found in External Build Files


*The following steps allow you to run the app on an Android Emulator as well as changing the default orientation to Portrait mode*
* In *grade.properties (Project Properties)* found in Gradle Scripts in Android Studio change the line: 

    **PROP_APP_ABI=armeabi** to
    **PROP_APP_ABI=armeabi:x86**
* In *Application.mk* found under the External Build Files change:

        "**APP_ABI := armeabi**" to   
        "**APP_ABI := x86**" 
* In *AndroidManifest.xml* found in **Prototype > manifests** change:
    
        "**android:screenOrientation="landscape"**" to
        "**android:screenOrientation="portrait"**"