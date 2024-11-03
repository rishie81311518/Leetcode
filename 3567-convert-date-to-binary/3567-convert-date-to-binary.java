class Solution {
public String convertDateToBinary(String date) {
        String[] dateParts = date.split("-");
        String yearBinaryStr = Integer.toBinaryString(Integer.parseInt(dateParts[0]));
        String monthBinaryStr = Integer.toBinaryString(Integer.parseInt(dateParts[1]));
        String dayBinaryStr = Integer.toBinaryString(Integer.parseInt(dateParts[2]));
    
    return yearBinaryStr+"-"+monthBinaryStr+"-"+dayBinaryStr;  
    }

};