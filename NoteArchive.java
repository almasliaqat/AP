
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author aliaqat.bscs13seecs
 */
public class NoteArchive implements java.io.Serializable{
    
    String username;
        String[] notes;
        
        public NoteArchive(String uname)
        {
            this.username=uname;
        }
        
        public NoteArchive(String uname, String note)
        {
            this.username=uname;
            int size=this.notes.length;
            if(size==0)
            this.notes[size]=note;
            else
             this.notes[size-1]=note;   
        }
    
}
