/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wmacevoy.test.oop;

import java.util.ArrayList;
import java.util.Iterator;


/**
 *
 * @author wmacevoy
 */
public class TestMe {
    public ArrayList < Integer > intArray = new ArrayList < Integer > ();
    public void resetIntArray() {
        intArray.clear();
        for (int i=0; i<3; ++i) {
            intArray.add(2*i-5);
        }
    }
    
    public int getThirdElement() {
        Iterator < Integer > i = intArray.iterator();
        i.next();
        i.next();
        return i.next();
    }
    
    void testThis() {
        assert 1 == 3;
    }
    
    void testThat() {
        assert "alice" == "bob";
    }
    
    public void test() {
        testThis();
        testThat();
    }
    public static void main(String [] args) {
        TestMe me = new TestMe();
        me.test();
    }
    
    
}
