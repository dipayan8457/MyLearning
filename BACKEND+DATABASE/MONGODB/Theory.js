//show dbs - show all databases
//CREATE
//use db_name->db.createCollection("collection_name")->create a database
//db.collection_name.insertOne({...})->insert one document
//db.collection_name.insertMany([{...},{...}....])->]insert many documents
//READ
//db.collection_name.find()->fetch all documents
//db.collection_name.find({ },{ })->fetch a particulr document(AND operation)
//db.collection_name.find({$or:[{ },{ }]})->fetch a particulr document(OR operation)
//use {array_name:{$in:[ ]}} for a document having one of the array elements,{$lt/gt:}->less than/greater than
//.findOne->first document,.findMany->all documents
//UPDATE
//db.collection_name.updateMany({filter},{$set:{ }})->updates all documents having the filter
//fields can be added as well
//DELETE
//db.collection_name.deleteMany({filter})->deletes all documents having the filter
//SORT AND LIMIT
//db.collection_name.find({filter}).sort({roll:1})->sorts in ascending order of roll(put -1 for descending order)
//db.collection_name.find({filter}).skip(no.of first documents to be skipped).limit(no.of documents to be displayed on output)
//MongoDB Atlas-cloud database
//AGGREGATION PIPELINE
/*db.collection_name.aggregate([
    {
        $match:{filter}->filter for all
    },
    {
        $group: {id="$name",totalquantity:{$sum:"$quantity"}}->filter by name as id and add all quanitfiable properties and store in totalquantity
    }
]
*/