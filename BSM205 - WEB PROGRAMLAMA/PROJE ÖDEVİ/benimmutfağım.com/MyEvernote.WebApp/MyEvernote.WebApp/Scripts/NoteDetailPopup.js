$(function () {

    $('#modal_notedetail').on('show.bs.modal', function (e) {

        var btn = $(e.relatedTarget);
        noteid = btn.data("note-id");

        $("#modal_notedetail_body").load("/Note/GetNoteText/" + noteid);
    })

});