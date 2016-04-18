/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practice;

import java.util.ArrayList;
import java.util.Stack;

/**
 *
 * @author Chand
 */
class Solution {

    String getSoln(Integer[] intArr, int target) {
        if (intArr.length > 1) {
            ArrayList<String[]> Signs = getSigns(intArr.length - 1);
            ArrayList<Integer[]> oprndComb = PermuteOperands(intArr);
            for (Integer[] opArr : oprndComb) {
                for (String[] stkSigns : Signs) {
                    try {
                        getExpr(opArr, stkSigns, target);
                    } catch (ArithmeticException e) {
                        //Do nothing
                    }
                    if (!solnStr.equals("")) {
                        solnStr += "=" + (new Integer(target)).toString();
                        return solnStr;
                    }
                }
            }
        }
        return "None";
    }

    private String solnStr = "";

    void getExpr(Integer[] oprnds, String[] oprtrs, int target) throws ArithmeticException {
        String tempStr = solnStr;
        String curOprtr = oprtrs[0];
        Integer oprnd1 = oprnds[0];
        Integer oprnd2 = oprnds[1];
        String[] newoprtrs = new String[oprtrs.length - 1];
        for (int i = 1; i < oprtrs.length; i++) {
            newoprtrs[i - 1] = oprtrs[i];
        }
        int result1 = 0;
        int result2 = 0;
        try {
            result1 = calculate(oprnd1, oprnd2, curOprtr);
            result2 = calculate(oprnd2, oprnd1, curOprtr);
        } catch (ArithmeticException e) {
            solnStr = "";
            throw e;
        }
        if (oprtrs.length == 1) {
            if (result1 == target) {
                if (!tempStr.equals("")) {
                    solnStr = tempStr + curOprtr + oprnd2.toString();
                } else {
                    solnStr = oprnd1.toString() + curOprtr + oprnd2.toString();
                }
                //return solnStr;
            } else if (result2 == target) {
                if (!tempStr.equals("")) {
                    solnStr = oprnd2.toString() + curOprtr + tempStr;
                } else {
                    solnStr = oprnd2.toString() + curOprtr + oprnd1.toString();
                }
                //return solnStr;
            } else {
                solnStr = "";
            }

        } else {

            Integer[] newoprnds = new Integer[oprnds.length - 1];
            newoprnds[0] = result1;
            for (int i = 2; i < oprnds.length; i++) {
                newoprnds[i - 1] = oprnds[i];
            }
            if (!tempStr.equals("")) {
                solnStr = "(" + tempStr + curOprtr + oprnd2.toString() + ")";
            } else {
                solnStr = "(" + oprnd1.toString() + curOprtr + oprnd2.toString() + ")";
            }
            getExpr(newoprnds, newoprtrs, target);

            if (!tempStr.equals("")) {
                solnStr = "(" + oprnd2.toString() + curOprtr + tempStr + ")";
            } else {
                solnStr = "(" + oprnd2.toString() + curOprtr + oprnd1.toString() + ")";
            }
            newoprnds[0] = result2;
            getExpr(newoprnds, newoprtrs, target);

        }

        //return solnStr;
    }

    ArrayList<Integer[]> PermuteOperands(Integer[] A) {
        ArrayList<Integer[]> result = new ArrayList();
        if (A.length == 1) {
            result.add(A);
            return result;
        }

        for (int i = 0; i < A.length; i++) {
            Integer[] subArr = new Integer[A.length - 1];
            boolean isNumRep = false;
            for (int j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    isNumRep = true;
                    break;
                }
                subArr[j] = A[j];
            }
            if (isNumRep) {
                continue;
            }
            for (int j = i + 1; j < A.length; j++) {
                subArr[j - 1] = A[j];
            }
            ArrayList<Integer[]> tempres = PermuteOperands(subArr);
            for (Integer[] temp : tempres) {
                Integer[] temp1 = new Integer[A.length];
                temp1[0] = A[i];
                for (int j = 0; j < temp.length; j++) {
                    temp1[j + 1] = temp[j];
                }
                result.add(temp1);
            }
        }
        return result;
    }

    int calculate(int x, int y, String sgn) throws ArithmeticException {
        int res = -1;

        switch (sgn) {
            case "+":
                return x + y;
            case "-":
                return x - y;
            case "*":
                return x * y;
            case "/":
                if (y != 0) {
                    if (x % y == 0) {
                        return x / y;
                    } else {
                        throw new ArithmeticException();
                    }
                } else {
                    throw new ArithmeticException();
                }
        }

        return res;

    }

    ArrayList<String[]> getSigns(int n) {
        String[] sSigns = {"+", "-", "*", "/"};
        ArrayList<String[]> arr = new ArrayList<String[]>();
        if (n == 1) {
            for (String s : sSigns) {
                String[] stk = new String[1];
                stk[0] = s;
                arr.add(stk);
            }
            return arr;
        }

        ArrayList<String[]> temparr = getSigns(n - 1);
        for (String s : sSigns) {
            for (String[] sArr : temparr) {
                String[] subStk = new String[sArr.length + 1];
                subStk[0] = s;
                System.arraycopy(sArr, 0, subStk, 1, sArr.length);
                arr.add(subStk);
            }
        }

        return arr;
    }

}

public class Arithemetics {

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Not enough aguments...!!!");
        } else {
            try {
                Integer[] intStk = new Integer[args.length - 1];

                for (int i = 0; i < args.length - 1; i++) {
                    intStk[i] = Integer.parseInt(args[i + 1]);
                }
                Solution s = new Solution();
                //ArrayList<Integer[]> res = s.PermuteOperands(intStk);
                System.out.println(s.getSoln(intStk, Integer.parseInt(args[0])));
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }

}
