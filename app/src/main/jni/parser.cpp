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
    jlongArray _dictionary_5
)
{
    FILE * f = fopen("/mnt/sdcard/data_en.bin", "wb");

    if (f != NULL) {
        __android_log_write(ANDROID_LOG_DEBUG, "Parser", "File open");
    } else {
        return;
    }

    jlong * dictionary = env->GetLongArrayElements(_dictionary, 0);
    jlong dictionary_len = (jlong) env->GetArrayLength(_dictionary);
    fwrite(&dictionary_len, sizeof (jlong), 1, f);
    fwrite(dictionary, sizeof (jlong), (size_t) dictionary_len, f); //    delete[] dictionary;
    char text[32];
    sprintf(text, "Dictionary - %lld", dictionary_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic2_more = env->GetLongArrayElements(_dic2_more, 0);
    jlong dic2_more_len = (jlong) env->GetArrayLength(_dic2_more);
    fwrite(&dic2_more_len, sizeof (jlong), 1, f);
    fwrite(dic2_more, sizeof (jlong), (size_t) dic2_more_len, f); //    delete[] dic2_more;
    sprintf(text, "dic2_more - %lld", dic2_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic3_more = env->GetLongArrayElements(_dic3_more, 0);
    jlong dic3_more_len = (jlong) env->GetArrayLength(_dic3_more);
    fwrite(&dic3_more_len, sizeof (jlong), 1, f);
    fwrite(dic3_more, sizeof (jlong), (size_t) dic3_more_len, f); //   delete[] dic3_more;
    sprintf(text, "dic3_more - %lld", dic3_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic4_more = env->GetLongArrayElements(_dic4_more, 0);
    jlong dic4_more_len = (jlong) env->GetArrayLength(_dic4_more);
    fwrite(&dic4_more_len, sizeof (jlong), 1, f);
    fwrite(dic4_more, sizeof (jlong), (size_t) dic4_more_len, f); //    delete[] dic4_more;
    sprintf(text, "dic4_more_len - %lld", dic4_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic5_more = env->GetLongArrayElements(_dic5_more, 0);
    jlong dic5_more_len = (jlong) env->GetArrayLength(_dic5_more);
    fwrite(&dic5_more_len, sizeof (jlong), 1, f);
    fwrite(dic5_more, sizeof (jlong), (size_t) dic5_more_len, f); //    delete[] dic5_more;
    sprintf(text, "dic5_more_len - %lld", dic5_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic6_more = env->GetLongArrayElements(_dic6_more, 0);
    jlong dic6_more_len = (jlong) env->GetArrayLength(_dic6_more);
    fwrite(&dic6_more_len, sizeof (jlong), 1, f);
    fwrite(dic6_more, sizeof (jlong), (size_t) dic6_more_len, f); //    delete[] dic6_more;
    sprintf(text, "dic6_more_len - %lld", dic6_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic7_more = env->GetLongArrayElements(_dic7_more, 0);
    jlong dic7_more_len = (jlong) env->GetArrayLength(_dic7_more);
    fwrite(&dic7_more_len, sizeof (jlong), 1, f);
    fwrite(dic7_more, sizeof (jlong), (size_t) dic7_more_len, f); //    delete[] dic7_more;
    sprintf(text, "dic7_more_len - %lld", dic7_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic8_more = env->GetLongArrayElements(_dic8_more, 0);
    jlong dic8_more_len = (jlong) env->GetArrayLength(_dic8_more);
    fwrite(&dic8_more_len, sizeof (jlong), 1, f);
    fwrite(dic8_more, sizeof (jlong), (size_t) dic8_more_len, f); //    delete[] dic8_more;
    sprintf(text, "dic8_more_len - %lld", dic8_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dic9_more = env->GetLongArrayElements(_dic9_more, 0);
    jlong dic9_more_len = (jlong) env->GetArrayLength(_dic9_more);
    fwrite(&dic9_more_len, sizeof (jlong), 1, f);
    fwrite(dic9_more, sizeof (jlong), (size_t) dic9_more_len, f); //    delete[] dic9_more;
    sprintf(text, "dic9_more_len - %lld", dic9_more_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    jlong * dictionary_5 = env->GetLongArrayElements(_dictionary_5, 0);
    jlong dictionary_5_len = (jlong) env->GetArrayLength(_dictionary_5);
    fwrite(&dictionary_5_len, sizeof (jlong), 1, f);
    fwrite(dictionary_5, sizeof (jlong), (size_t) dictionary_5_len, f); //    delete[] dictionary;
    sprintf(text, "Dictionary_5 - %lld", dictionary_5_len);
    __android_log_write(ANDROID_LOG_DEBUG, "Parser", text);

    fclose(f);
};
