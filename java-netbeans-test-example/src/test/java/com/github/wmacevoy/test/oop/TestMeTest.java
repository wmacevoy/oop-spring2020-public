/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.wmacevoy.test.oop;

import java.util.ArrayList;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author wmacevoy
 */
public class TestMeTest {
    
    public TestMeTest() {
    }
    
    @BeforeAll
    public static void setUpClass() {
    }
    
    @AfterAll
    public static void tearDownClass() {
    }
    
    @BeforeEach
    public void setUp() {
    }
    
    @AfterEach
    public void tearDown() {
    }

    /**
     * Test of resetIntArray method, of class TestMe.
     */
    @Test
    public void testResetIntArray() {
        System.out.println("resetIntArray");
        TestMe instance = new TestMe();
        instance.resetIntArray();
        ArrayList<Integer> expect = new ArrayList<Integer> ();
        expect.add(-5);
        expect.add(-3);
        expect.add(-1);
        assertEquals(expect, instance.intArray);
    }

    /**
     * Test of getThirdElement method, of class TestMe.
     */
    @Test
    public void testGetThirdElement() {
        System.out.println("resetIntArray");
        TestMe instance = new TestMe();
        instance.resetIntArray();
        int expect = -1;
        assertEquals(expect, instance.getThirdElement());
    }
    
}
