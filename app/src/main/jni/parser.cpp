#include <jni.h>
#include "parser.h"
#include <stdio.h>
#include <android/log.h>

void Java_es_hol_chernyshov_parserdictionary_Parser_hello
        (JNIEnv *, jobject)
{
    //return 1;
};

void Java_es_hol_chernyshov_parserdictionary_Parser_saveData (
    JNIEnv * env,
    jclass obj,
    jlongArray _dictionary,
    jlongArray _dic2_more,
    jlongArray _dic3_more,
    jlongArray _dic4_more,
    jlongArray _dic5_more,
    jlongArray _dic6_more,
    jlongArray _dic7_more,
    jlongArray _dic8_more,
    jlongArray _dic9_more,
    jlongArray _dictionary5
)
{
    FILE * f = fopen("/storage/sdcard/Download/data_en.bin", "w+");
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", "JNI begin");

//    jlong * dictionary = env->GetLongArrayElements(_dictionary, 0);
//    jlong dictionary_len = (jlong) env->GetArrayLength(_dictionary);
//    fwrite(&dictionary_len, sizeof (jlong), 1, f);
//    fwrite(dictionary, sizeof (jlong), dictionary_len, f);
//    delete[] dictionary;
    jlong jlong1 = 5L;
    if (f != NULL) {
        fwrite(&jlong1, sizeof (jlong), 1, f);
    }

    __android_log_write(ANDROID_LOG_DEBUG, "Parser", "ictionary - ");    //cout << "dictionary - " << dictionary_len << endl;

//    jlong * dic2_more = env->GetLongArrayElements(_dic2_more, 0);
//    jlong dic2_more_len = (jlong) env->GetArrayLength(_dic2_more);
//    fwrite(&dic2_more_len, sizeof (jlong), 1, f);
//    fwrite(dic2_more, sizeof (jlong), dic2_more_len, f);
//    delete[] dic2_more;
//    //cout << "dic2_more - " << dic2_more_len << endl;
//
//    jlong * dic3_more = env->GetLongArrayElements(_dic3_more, 0);
//    jlong dic3_more_len = (jlong) env->GetArrayLength(_dic3_more);
//    fwrite(&dic3_more_len, sizeof (jlong), 1, f);
//    fwrite(dic3_more, sizeof (jlong), dic3_more_len, f);
//    delete[] dic3_more;
//    //cout << "dic3_more - " << dic3_more_len << endl;
//
//    jlong * dic4_more = env->GetLongArrayElements(_dic4_more, 0);
//    jlong dic4_more_len = (jlong) env->GetArrayLength(_dic4_more);
//    fwrite(&dic4_more_len, sizeof (jlong), 1, f);
//    fwrite(dic4_more, sizeof (jlong), dic4_more_len, f);
//    delete[] dic4_more;
//    //cout << "dic4_more - " << dic4_more_len << endl;
//
//    jlong * dic5_more = env->GetLongArrayElements(_dic5_more, 0);
//    jlong dic5_more_len = (jlong) env->GetArrayLength(_dic5_more);
//    fwrite(&dic5_more_len, sizeof (jlong), 1, f);
//    fwrite(dic5_more, sizeof (jlong), dic5_more_len, f);
//    delete[] dic5_more;
//    //cout << "dic5_more - " << dic5_more_len << endl;
//
//    jlong * dic6_more = env->GetLongArrayElements(_dic6_more, 0);
//    jlong dic6_more_len = (jlong) env->GetArrayLength(_dic6_more);
//    fwrite(&dic6_more_len, sizeof (jlong), 1, f);
//    fwrite(dic6_more, sizeof (jlong), dic6_more_len, f);
//    delete[] dic6_more;
//    //cout << "dic6_more - " << dic6_more_len << endl;
//
//    jlong * dic7_more = env->GetLongArrayElements(_dic7_more, 0);
//    jlong dic7_more_len = (jlong) env->GetArrayLength(_dic7_more);
//    fwrite(&dic7_more_len, sizeof (jlong), 1, f);
//    fwrite(dic7_more, sizeof (jlong), dic7_more_len, f);
//    delete[] dic7_more;
//    //cout << "dic7_more - " << dic7_more_len << endl;
//
//    jlong * dic8_more = env->GetLongArrayElements(_dic8_more, 0);
//    jlong dic8_more_len = (jlong) env->GetArrayLength(_dic8_more);
//    fwrite(&dic8_more_len, sizeof (jlong), 1, f);
//    fwrite(dic8_more, sizeof (jlong), dic8_more_len, f);
//    delete[] dic8_more;
//    //cout << "dic8_more - " << dic8_more_len << endl;
//
//    jlong * dic9_more = env->GetLongArrayElements(_dic9_more, 0);
//    jlong dic9_more_len = (jlong) env->GetArrayLength(_dic9_more);
//    fwrite(&dic9_more_len, sizeof (jlong), 1, f);
//    fwrite(dic9_more, sizeof (jlong), dic9_more_len, f);
//    delete[] dic9_more;
//    //cout << "dic9_more - " << dic9_more_len << endl;
//
//    //cout << "JNI end" << endl;
    fclose(f);
//    return 0;
};
