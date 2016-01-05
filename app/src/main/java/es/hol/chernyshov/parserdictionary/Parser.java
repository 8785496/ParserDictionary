package es.hol.chernyshov.parserdictionary;

public class Parser {
    static {
        System.loadLibrary("parser");
    }

    public static native void hello();

    public static native void saveData(
            long[] dictionary,
            long[] dic2_more,
            long[] dic3_more,
            long[] dic4_more,
            long[] dic5_more,
            long[] dic6_more,
            long[] dic7_more,
            long[] dic8_more,
            long[] dic9_more,
            long[] dictionary5
    );
}
