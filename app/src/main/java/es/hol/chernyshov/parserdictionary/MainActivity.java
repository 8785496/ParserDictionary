package es.hol.chernyshov.parserdictionary;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MainActivity extends Activity {
    private static final ArrayList<String> words = new ArrayList<>();
    private static String chars;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    private void parserRussian() {
        String dir = Environment.getExternalStorageDirectory().getAbsolutePath();
        Log.d("Parser", dir);
        String filename = "data.bin";

        try {
            File myFile = new File(dir, filename);
            if (!myFile.delete()) {
                Log.e("Parser", "File not deleted");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        AssetManager assetManager = getResources().getAssets();
        try {
            InputStreamReader inputStreamReader = new InputStreamReader(assetManager.open("efremova.txt"), "cp1251");
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
            Pattern p = Pattern.compile("^\\s(1\\.\\s)?(м|ж|ср)\\..*$");
            Pattern p2 = Pattern.compile("^[а-я]+");
            Pattern p3 = Pattern.compile("^\\sI.*");
            String line;
            String prevLine = "";
            String prevPrevLine = "";
            int j = 0;
            while ((line = bufferedReader.readLine()) != null) {
                if (p.matcher(line).matches()) {
                    if (p2.matcher(prevLine).matches()) {
                        words.add(prevLine);
                    } else if (p3.matcher(prevLine).matches()) {
                        if (p2.matcher(prevPrevLine).matches()) {
                            words.add(prevPrevLine);
                        }
                    }
                }
                prevPrevLine = prevLine;
                prevLine = line;

                j++;
                if ((j % 10000) == 0) {
                    System.gc();
                }
            }

            for (int i = 0; i < 10; i++) {
                Log.d("Parser", words.get(i));
            }

            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void parserEnglish() {
        String dir = Environment.getExternalStorageDirectory().getAbsolutePath();
        Log.d("Parser", dir);
        String filename = "data_en.bin";

        try {
            File myFile = new File(dir, filename);
            if (!myFile.delete()) {
                Log.e("Parser", "File not deleted");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        AssetManager assetManager = getResources().getAssets();
        try {
            InputStreamReader inputStreamReader = new InputStreamReader(assetManager.open("aemuller.txt"), "cp1251");
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
            Pattern p = Pattern.compile("^\\s\\s\\s([a-z]+)\\s(1\\.\\s)?noun.*");
            String line;

            int j = 0;
            while ((line = bufferedReader.readLine()) != null) {

                Matcher m = p.matcher(line);
                if (m.matches()) {
                    words.add(m.group(1));
                }

                j++;

                if ((j % 1000) == 0) {
                    System.gc();
                }
            }

            for (int i = 0; i < 10; i++) {
                Log.d("Parser", words.get(i));
            }

            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void save() {
        ArrayList<Long> dictionary = new ArrayList<>();
        ArrayList<Long> dic2_more = new ArrayList<>();
        ArrayList<Long> dic3_more = new ArrayList<>();
        ArrayList<Long> dic4_more = new ArrayList<>();
        ArrayList<Long> dic5_more = new ArrayList<>();
        ArrayList<Long> dic6_more = new ArrayList<>();
        ArrayList<Long> dic7_more = new ArrayList<>();
        ArrayList<Long> dic8_more = new ArrayList<>();
        ArrayList<Long> dic9_more = new ArrayList<>();
        ArrayList<Long> dictionary_5 = new ArrayList<>();

        int n = 10;
        for (int i = 0; i < words.size(); i++) {
            String word = words.get(i);
            int len = word.length();
            if (len <= n) {
                // хэшируем словарь
                if (len > 1)
                    dictionary.add(str2hash(word));

                // хэшируем ,больше 2 и меньше N букв
                if (len > 2) {
                    long hash = str2hash(word.substring(0, 2));
                    if (dic2_more.size() == 0 || dic2_more.get(dic2_more.size() - 1) != hash)
                        dic2_more.add(hash);
                }
                // хэшируем ,больше 3 и меньше N букв
                if (len > 3) {
                    long hash = str2hash(word.substring(0, 3));
                    if (dic3_more.size() == 0 || dic3_more.get(dic3_more.size() - 1) != hash)
                        dic3_more.add(hash);
                }
                // хэшируем ,больше 4 и меньше N букв
                if (len > 4) {
                    long hash = str2hash(word.substring(0, 4));
                    if (dic4_more.size() == 0 || dic4_more.get(dic4_more.size() - 1) != hash)
                        dic4_more.add(hash);
                }
                // хэшируем ,больше 5 и меньше N букв
                if (len > 5) {
                    long hash = str2hash(word.substring(0, 5));
                    if (dic5_more.size() == 0 || dic5_more.get(dic5_more.size() - 1) != hash)
                        dic5_more.add(hash);
                }
                // хэшируем ,больше 6 и меньше N букв
                if (len > 6) {
                    long hash = str2hash(word.substring(0, 6));
                    if (dic6_more.size() == 0 || dic6_more.get(dic6_more.size() - 1) != hash)
                        dic6_more.add(hash);
                }
                // хэшируем ,больше 7 и меньше N букв
                if (len > 7) {
                    long hash = str2hash(word.substring(0, 7));
                    if (dic7_more.size() == 0 || dic7_more.get(dic7_more.size() - 1) != hash)
                        dic7_more.add(hash);
                }
                // хэшируем ,больше 8 и меньше N букв
                if (len > 8) {
                    long hash = str2hash(word.substring(0, 8));
                    if (dic8_more.size() == 0 || dic8_more.get(dic8_more.size() - 1) != hash)
                        dic8_more.add(hash);
                }
                // хэшируем ,больше 9 и меньше N букв
                if (len > 9) {
                    long hash = str2hash(word.substring(0, 9));
                    if (dic9_more.size() == 0 || dic9_more.get(dic9_more.size() - 1) != hash)
                        dic9_more.add(hash);
                }

                // хэшируем слова из 5 букв
                if (len == 5)
                    dictionary_5.add(str2hash(word));
            }
        }

        long[] long_dictionary = listToSortArray(dictionary);
        long[] long_dic2_more = listToSortArray(dic2_more);
        long[] long_dic3_more = listToSortArray(dic3_more);
        long[] long_dic4_more = listToSortArray(dic4_more);
        long[] long_dic5_more = listToSortArray(dic5_more);
        long[] long_dic6_more = listToSortArray(dic6_more);
        long[] long_dic7_more = listToSortArray(dic7_more);
        long[] long_dic8_more = listToSortArray(dic8_more);
        long[] long_dic9_more = listToSortArray(dic9_more);
        long[] long_dictionary_5 = listToSortArray(dictionary_5);

        Parser.saveData(
                long_dictionary, long_dic2_more,
                long_dic3_more, long_dic4_more,
                long_dic5_more, long_dic6_more,
                long_dic7_more, long_dic8_more,
                long_dic9_more, long_dictionary_5
        );
    }

    private static long[] listToSortArray(ArrayList<Long> arrayList) {
        long[] longArray = new long[arrayList.size()];
        for (int i = 0; i < arrayList.size(); i++) {
            longArray[i] = arrayList.get(i);
        }
        Arrays.sort(longArray);
        return longArray;
    }

    private static long str2hash(String word) {
        long id = 0L;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            String sym = word.substring(len - i - 1, len - i);
            id += (chars.indexOf(sym) + 0) * Math.pow(33, i);
        }
        return id;
    }

    public void saveEnglish(View view) {
        chars = " abcdefghijklmnopqrstuvwxyz";
        parserEnglish();
        save();
    }

    public void saveRussian(View view) {
        chars = " абвгдежзийклмнопрстуфхцчшщъыьэюя";
        parserRussian();
        save();
    }
}
