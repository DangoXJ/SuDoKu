LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := helloworld/main.cpp \
../../Classes/AppDelegate.cpp \
../../Classes/Config.cpp \
../../Classes/Extensions/CCScrollItem.cpp \
../../Classes/Extensions/CCScrollLayer.cpp \
../../Classes/Menu/DetailLevelInfo.cpp \
../../Classes/Menu/DetailLevelInfoLayer.cpp \
../../Classes/Menu/DetailLevelItem.cpp \
../../Classes/Menu/LevelInfo.cpp \
../../Classes/Menu/Menu.cpp \
../../Classes/SuDoKu/SuDoKuLayer.cpp \


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) $(call import-module,cocos2dx)
