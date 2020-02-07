using namespace std::placeholders;
const VcsBaseEditorParameters logEditorParameters {
    Constants::LOGAPP
};
const VcsBaseEditorParameters annotateEditorParameters {
    AnnotateOutput,
    Constants::ANNOTATEAPP
};
const VcsBaseEditorParameters diffEditorParameters {
    DiffOutput,
    Constants::DIFFAPP
const VcsBaseSubmitEditorParameters submitEditorParameters {
    void describe(const QString &source, const QString &id) { m_client.view(source, id); }


    VcsSubmitEditorFactory submitEditorFactory {
        submitEditorParameters,
        [] { return new CommitEditor; },
        this
    };

    VcsEditorFactory logEditorFactory {
        &logEditorParameters,
        [this] { return new MercurialEditorWidget(&m_client); },
        std::bind(&MercurialPluginPrivate::describe, this, _1, _2)
    };

    VcsEditorFactory annotateEditorFactory {
        &annotateEditorParameters,
        [this] { return new MercurialEditorWidget(&m_client); },
        std::bind(&MercurialPluginPrivate::describe, this, _1, _2)
    };

    VcsEditorFactory diffEditorFactory {
        &diffEditorParameters,
        [this] { return new MercurialEditorWidget(&m_client); },
        std::bind(&MercurialPluginPrivate::describe, this, _1, _2)
    };
    VcsBaseEditorWidget::testDiffFileResolving(diffEditorParameters.id);
    VcsBaseEditorWidget::testLogResolving(logEditorParameters.id, data, "18473:692cbda1eb50", "18472:37100f30590f");